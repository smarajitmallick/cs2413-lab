// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"    // Contains the struct definition
#include <stdlib.h>   // to access malloc() & free()
#include <stdbool.h>  // to get a bool type

MyCircularQueue* myCircularQueueCreate(int k) {
    if (k <= 0) return NULL; // if invalid capacity then return NULL

    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!obj) return NULL;  // If malloc() fails then return NULL 

    obj->data = (int*)malloc(sizeof(int) * k);
    if (!obj->data)    // if allocation fails 
    { 
        free(obj);     // Front index starts at 0
        return NULL;    // return null
    }

    obj->capacity = k;  // Has the maximum number of elements 
    obj->head = 0; // Front index starts at 0
    obj->tail = 0; // Next insertion spot
    obj->size = 0; 
    return obj;     // Return pointer to created queue


}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!obj || obj->size == obj->capacity) return false;   // if queue is full or invalid then false

    obj->data[obj->tail] = value; //  Insering value at tail position
    obj->tail = (obj->tail + 1) % obj->capacity;    //Moving tail forward
    obj->size++;        // Increasing the number of stored elements  

    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return false; // if queue is empty it cannot remove 

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;    // Decreasing the number of stored elemnts

    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return -1;     // if its empty then return -1 
    
    return obj->data[obj->head];    // Return element at front

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) return -1;  // if empty return -1
    // tail points to next insertion spot so last element is one position before tail
    int rearIndex = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[rearIndex];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (!obj) return true;  //Invalid pointer so treating it as empty
    return obj->size == 0;  // it is Empty if size = 0

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (!obj) return false; // invalid Pointer cause not full
    return obj->size == obj->capacity; // it is full if size equals capacity
 
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (!obj) return;   // if NULL 

    free(obj->data);    // Free internal array first
    free(obj);          // then free struct
  
}
