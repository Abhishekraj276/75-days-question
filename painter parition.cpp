#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &boards, int k, int mid) {
    int painters = 1;
    int current_sum = 0;

    for (int board : boards) {
        current_sum += board;
        if (current_sum > mid) {
            painters++;
            current_sum = board;
        }
    }

    return painters <= k;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int left = *max_element(boards.begin(), boards.end());
    int right = accumulate(boards.begin(), boards.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isPossible(boards, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}


int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int result = findLargestMinDistance(boards, k);
    cout << result << endl;

    return 0;
}

