#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {

    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }

        swap(&nums[i], &nums[j]);
    }

    reverse(nums, i + 1, numsSize - 1);
}

int main() {
 
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    nextPermutation(arr, size);

    printf("\nNext permutation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

