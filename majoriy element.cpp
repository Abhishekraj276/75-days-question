#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];  
    int count = 1;  


    for (int i = 1; i < numsSize; i++) {
       
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
   
            count++;
        } else {
         
            count--;
        }
    }

    return candidate;
}

int main() {
 
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = majorityElement(arr, size);
    printf("Majority Element: %d\n", result);

    return 0;
}

