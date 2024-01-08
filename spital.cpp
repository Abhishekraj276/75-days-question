#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int top = 0, bottom = matrixSize - 1, left = 0, right = *matrixColSize - 1;
    int* result = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    *returnSize = 0;

    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int i = left; i <= right; ++i) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        // Traverse rightmost column
        for (int i = top; i <= bottom; ++i) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                result[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Traverse leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

int main() {
    int matrixSize1 = 3, matrixColSize1 = 3;
    int* matrix1[3] = {
        (int[]){1, 2, 3},
        (int[]){4, 5, 6},
        (int[]){7, 8, 9}
    };

    int returnSize1;
    int* result1 = spiralOrder(matrix1, matrixSize1, &matrixColSize1, &returnSize1);

    printf("Spiral Order 1: ");
    for (int i = 0; i < returnSize1; ++i) {
        printf("%d ", result1[i]);
    }
    printf("\n");

    // You can add more test cases if needed.

    // Free allocated memory
    free(result1);

    return 0;
}

