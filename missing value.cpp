#include <stdio.h>

int missingNumber(int nums[], int length) {
    int* count = calloc(length + 1, sizeof(int));
    
    for (int i = 0; i < length; i++) {
        count[nums[i]]++;
    }

    for (int i = 0; i <= length; i++) {
        if (count[i] == 0) {
            free(count);  // Don't forget to free allocated memory
            return i;
        }
    }

    free(count);
    return -1;
}

int main() {
    int nums[] = {3, 0, 1};
    int length = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, length);
    printf("The missing number is: %d\n", result);

    return 0;
}

