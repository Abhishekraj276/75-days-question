#include <stdio.h>

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int totalPoints = 0;
    for (int i = 0; i < cardPointsSize; i++) {
        totalPoints += cardPoints[i];
    }

    int windowSize = cardPointsSize - k;
    int currentWindowSum = 0;

    for (int i = 0; i < windowSize; i++) {
        currentWindowSum += cardPoints[i];
    }

    int minWindowSum = currentWindowSum;
    for (int i = windowSize; i < cardPointsSize; i++) {
        currentWindowSum += cardPoints[i] - cardPoints[i - windowSize];
        minWindowSum = (minWindowSum < currentWindowSum) ? minWindowSum : currentWindowSum;
    }

    return totalPoints - minWindowSum;
}

int main() {
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int cardPointsSize = sizeof(cardPoints) / sizeof(cardPoints[0]);
    int k = 3;

    int result = maxScore(cardPoints, cardPointsSize, k);

    printf("Maximum score: %d\n", result);

    return 0;
}

