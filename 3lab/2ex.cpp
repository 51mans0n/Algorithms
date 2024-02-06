#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& ghouls, int k, long long mid) {
    int n = ghouls.size();
    int blocks = 1;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (ghouls[i] > mid) {
            return false;
        }

        current_sum += ghouls[i];

        if (current_sum > mid) {
            blocks++;
            current_sum = ghouls[i];
        }
    }

    return blocks <= k;
}

long long findMinMaxGhouls(vector<int>& ghouls, int k) {
    long long left = 1;
    long long right = 1e18;
    long long result = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (isPossible(ghouls, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ghouls(n);

    for (int i = 0; i < n; ++i) {
        cin >> ghouls[i];
    }

    long long minMaxGhouls = findMinMaxGhouls(ghouls, k);
    cout << minMaxGhouls << endl;

    return 0;
}