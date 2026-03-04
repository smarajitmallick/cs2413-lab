// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    // TODO: implement
    // Hints (optional):
    // - Keep track of previous and current pointers.
    // - Iterate until current becomes NULL.

    // getting the previous pointer (initially NULL)
    struct ListNode* previous = NULL;

    // getting the current pointer which starts at head
    struct ListNode* current = head;

    // getting a temporary pointer to store next node
    struct ListNode* next = NULL;

    // traversing the list
    while (current != NULL) {
        // saving the next node
        next = current->next;

        // reversing the current node's pointer
        current->next = previous;

        // moving previous and current one step forward
        previous = current;
        current = next;
    }

    // previous will be the new head
    return previous;


}