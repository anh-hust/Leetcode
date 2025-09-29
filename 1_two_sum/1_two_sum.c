/*
    Date 2025-8-19
    Author: Alfie_Bui
    Description: Leet Code -> Problem -> All Topics -> 1

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct htable {
    int number_value;
    int index;
};

void twoSum_advanced(int* nums, int numsSize, int target, int* retval) {
    struct htable* store_tbl = malloc(sizeof(struct htable));
    

    free(store_tbl);
}

void twoSum_bruce_force(int* nums, int numsSize, int target, int* retval) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                retval[0] = i;
                retval[1] = j;
                return;
            }
        }
    }
}

int main() {
    int array[] = { 1, 3, 5, 2, 4, 6, 8, 7, 9, 12, 14, 11 };
    int array_size = sizeof(array) / sizeof(array[0]);
    int target = 13;

    int* retval = (int*)malloc(2 * sizeof(int));
    retval[0] = -1;
    retval[1] = -1;

    twoSum(array, array_size, target, retval);

    if (retval[0] == -1 || retval[1] == -1) {
        printf("[x] Target %d on array cannot match !!", target);
    } else {
        printf("[v] Target %d on array match, index [%d, %d] = %d + %d", target, retval[0], retval[1], array[retval[0]], array[retval[1]]);
    }

    free(retval);
    return 0;
}
