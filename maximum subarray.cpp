#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];
        maxSum = (maxSum > currentSum) ? maxSum : currentSum;
    }

    return maxSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maxSubArray(nums, numsSize);

    printf("Maximum subarray sum: %d\n", result);

    return 0;
}

