// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // TODO: implement

    // if list is empty or has only one node then it cannot have a cycle.
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // slow pointer moves 1 step at a time
    struct ListNode *slow_pointer = head;

    // fast pointer moves 2 steps at a time
    struct ListNode *fast_pointer = head;

    // traversing the list
    while (fast_pointer != NULL && fast_pointer->next != NULL) {

        // moving pointers
        slow_pointer = slow_pointer->next;          // 1 step
        fast_pointer = fast_pointer->next->next;    // 2 steps

        // if they meet, cycle exists
        if (slow_pointer == fast_pointer) {
            return true;
        }
    }

    // if fast reaches NULL, no cycle
    return false;


}