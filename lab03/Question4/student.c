// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement

    // if list is empty returning 0 or handle error
    if (head == NULL) {
        return 0;   // or handle as required
    }

    // slow pointer moves 1 step
    struct ListNode *slow_pointer = head;

    // fast pointer moves 2 steps
    struct ListNode *fast_pointer = head;

    // moving until fast reaches end
    while (fast_pointer != NULL && fast_pointer->next != NULL) {
        slow_pointer = slow_pointer->next;           // move 1 step
        fast_pointer = fast_pointer->next->next;     // move 2 steps
    }

    // When loop ends:
    // - slow is at middle
    // - if even length, slow is at second middle 

    return slow_pointer->val;

}