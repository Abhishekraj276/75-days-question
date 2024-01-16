#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        }
    }

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

 
    return numsSize + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = firstMissingPositive(nums, numsSize);
    printf("%d\n", result);

    return 0;
}

