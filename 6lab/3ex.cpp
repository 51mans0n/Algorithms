#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int minAbsDiff = INT_MAX;
    vector<pair<int, int>> minPairs;

    for (int i = 1; i < N; i++) {
        int absDiff = points[i] - points[i - 1];

        if (absDiff < minAbsDiff) {
            minAbsDiff = absDiff;
            minPairs.clear();
            minPairs.push_back({points[i - 1], points[i]});
        } else if (absDiff == minAbsDiff) {
            minPairs.push_back({points[i - 1], points[i]});
        }
    }

    for (const auto& pair : minPairs) {
        cout << pair.first << " " << pair.second << " ";
    }

    cout << endl;

    return 0;
}