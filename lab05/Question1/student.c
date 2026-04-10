/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

#include <stdlib.h>

/*
Node structure for hash table (linked list for collision handling)
key   -> number from array
value -> index of that number
*/
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/*
Prime number table size helps reduce collisions
*/
#define TABLE_SIZE 1009

/*
Hash function:
Ensures index is always non-negative and within table size
*/
static int hash(int key) {
    if (key < 0) key = -key;          // handles negative keys
    return key % TABLE_SIZE;          // mapping key to index
}

/*
Inserting (key, value) into hash table
Uses chaining (linked list) to handle collisions
*/
static void insert(Node* table[], int key, int value) {
    int index = hash(key);            // computing hash index

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;

    // Inserting at head of linked list
    newNode->next = table[index];
    table[index] = newNode;
}

/*
Finding a key in the hash table
If found:
    - store index in *value
    - return 1 (true)
Else return 0 (false)
*/
static int find(Node* table[], int key, int* value) {
    int index = hash(key);            // computing hash index
    Node* curr = table[index];

    // Traversing linked list at this index
    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;     // storing index
            return 1;                 // found 
        }
        curr = curr->next;
    }
    return 0;                         // not found
}

/*
Free all memory used by hash table
*/
static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);               // free each node
        }
    }
}

/*
Main function: Two Sum
Returns indices of two numbers that add up to target
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    // Allocating hash table and initializing to NULL
    Node* table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    // Iterating through array
    for (int i = 0; i < numsSize; i++) {

        int complement = target - nums[i];  // number we need

        int foundIndex;

        // Checking if complement already exists in hash table
        if (find(table, complement, &foundIndex)) {

            // Allocatingresult array of size 2
            int* result = (int*)malloc(2 * sizeof(int));

            result[0] = foundIndex;  // index of complement
            result[1] = i;           // current index

            *returnSize = 2;

            // Free hash table before returning
            freeTable(table);

            return result;
        }

        // If not found, insert current number into hash table
        insert(table, nums[i], i);
    }

    // If no solution (though problem guarantees one)
    *returnSize = 0;
    freeTable(table);
    return NULL;
}