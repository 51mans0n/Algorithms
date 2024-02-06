#include <iostream>
#include <vector>

using namespace std;

bool canStealAll(vector<int>& bags, int K, int H) {
    long long hoursNeeded = 0;
    int maxBag = 0;
    
    for (int b : bags) {
        if (b > maxBag) maxBag = b;
    }
    
    for (int b : bags) {
        hoursNeeded += (b + K - 1) / K;
    }
    
    return hoursNeeded <= H;
}

int findMinimumK(vector<int>& bags, int H) {
    int left = 1, right = 1;
    for (int b : bags) {
        if (b > right) right = b;
    }
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canStealAll(bags, mid, H)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> bags(N);

    for (int i = 0; i < N; ++i) {
        cin >> bags[i];
    }

    int minK = findMinimumK(bags, H);
    cout << minK << endl;

    return 0;
}