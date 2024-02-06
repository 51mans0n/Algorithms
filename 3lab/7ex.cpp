#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& islands, int f, int mid) {
    int flights = 0;
    for (int i = 0; i < islands.size(); ++i) {
        flights += (islands[i] + mid - 1) / mid; 
    }
    return flights <= f;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> islands(n);
    for (int i = 0; i < n; ++i) {
        cin >> islands[i];
    }

    int left = 1; 
    int right = *max_element(islands.begin(), islands.end()); 
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(islands, f, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (ans!= 0)
        cout << ans << endl;
    else
        cout << 1 << endl;

    return 0;
}