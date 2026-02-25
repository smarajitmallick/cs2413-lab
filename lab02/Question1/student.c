// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>    // for boolean type
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h> // for malloc / free

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.
    // Returning false if input pointer is NULL (invalid input)
    if (s == NULL) return false;
    // Getting the legth of string
    size_t len = strlen(s);
    // Odd-length strings can never be valid (must be pairs) so returning false 
    if (len % 2 != 0) return false;
    if (len == 0) return true;  // Empty strings are valid 

    // Dynamically allocate stack
    char *stack = (char *)malloc(len * sizeof(char));
    if (stack == NULL) return false;  // If allocation fails, returning false

    int top = -1;
    // Traversing string character by character
    for (size_t i = 0; i < len; i++) {
        char c = s[i];  // Extracting current character

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;       //Incrementing top then store
        } else {
            if (top < 0) {
                free(stack);
                return false;
            }

            char open = stack[top--];   // Pop the top

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                free(stack);
                return false;
            }
        }
    }

    // If stack is empty, all brackets matched correctly
    bool valid = (top == -1);
    free(stack);    // Free allocated stack memory
    return valid;
    return false;
  
}
