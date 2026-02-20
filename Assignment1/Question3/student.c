#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // TODO: implement

    // Calculating the maximum possible size
    int* outcome = (int*)malloc(sizeof(int) * (digitsSize + 1)); 


    for (int i = 0; i < digitsSize; i++) {
        outcome[i] = digits[i];
    }

    // Adding one from the end
    int carryover = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = outcome[i] + carryover;
        outcome[i] = sum % 10;
        carryover = sum / 10;
    }

    // If carry == 1, shifting array and adding 1 at the front
    if (carryover == 1) {
        for (int i = digitsSize; i > 0; i--) {
            outcome[i] = outcome[i-1];
        }
        outcome[0] = 1;
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
    }

    return outcome;
}



    


