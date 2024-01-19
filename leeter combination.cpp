#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getLetters(char digit) {
    switch (digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

void backtrack(char* digits, char* combination, char** result, int* index, int depth) {
    if (digits[depth] == '\0') {
        combination[depth] = '\0';
        result[*index] = strdup(combination);
        (*index)++;
        return;
    }

    char* letters = getLetters(digits[depth]);
    int len = strlen(letters);

    for (int i = 0; i < len; i++) {
        combination[depth] = letters[i];
        backtrack(digits, combination, result, index, depth + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int totalCombinations = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        totalCombinations *= strlen(getLetters(digits[i]));
    }

    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    for (int i = 0; i < totalCombinations; i++) {
        result[i] = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    }

    int index = 0;
    char* combination = (char*)malloc((strlen(digits) + 1) * sizeof(char));

    backtrack(digits, combination, result, &index, 0);

    *returnSize = index;

    free(combination);

    return result;
}

int main() {
    char digits[] = "23";
    int returnSize;
    char** result = letterCombinations(digits, &returnSize);

    printf("Letter Combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);

    return 0;
}

