#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sheep {
    int x1, y1, x2, y2;
};

bool canFit(const vector<Sheep>& sheeps, int k, int side) {
    int count = 0;
    for (const Sheep& sheep : sheeps) {
        if (sheep.x2 <= side && sheep.y2 <= side) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Sheep> sheeps(n);

    for (int i = 0; i < n; i++) {
        cin >> sheeps[i].x1 >> sheeps[i].y1 >> sheeps[i].x2 >> sheeps[i].y2;
    }

    int left = 0, right = 1000000000; 
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFit(sheeps, k, mid)) {
            result = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}