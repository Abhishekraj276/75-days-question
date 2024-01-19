#include <stdio.h>

void sortZeroesAndOne(int input[], int size) {
    int left = 0;    // Pointer for 0's
    int right = size - 1;  // Pointer for 1's

    while (left < right) {
        // Move left pointer to the right until a 1 is found
        while (input[left] == 0 && left < right) {
            left++;
        }

        // Move right pointer to the left until a 0 is found
        while (input[right] == 1 && left < right) {
            right--;
        }

        // Swap 0 and 1
        if (left < right) {
            input[left] = 0;
            input[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    // Example usage:
    int arr[] = {1, 0, 1, 0, 0, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    sortZeroesAndOne(arr, size);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

