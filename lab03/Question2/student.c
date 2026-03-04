// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      // if list is empty or has only one node then nothing to swap.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // new head will be the second node because first pair gets swapped.
    struct ListNode* newHead = head->next;

    // pointing to previous pair's second node (used to connect pairs together)
    struct ListNode* previous = NULL;

    // current pointer starts at head
    struct ListNode* current = head;

    // traversing in pairs
    while (current != NULL && current->next != NULL) {

        // identifing the two nodes to swap
        struct ListNode* first = current;
        struct ListNode* second = current->next;

        // saving the start of the next pair
        struct ListNode* nextPair = second->next;

        // swap 

        // second pointing to first (reversing the pair)
        second->next = first;

        // pointing to the next pair
        first->next = nextPair;

        // connecting previous pair to this swapped pair
        if (previous != NULL) {
            previous->next = second;
        }

        // moving previous to the end of the swapped pair
        previous = first;

        // moving trhe current to next pair
        current = nextPair;
    }

    return newHead;

}