#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> densities(n);
    for (int i = 0; i < n; ++i) {
        cin >> densities[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq(densities.begin(), densities.end());

    int operations = 0;

    while (!pq.empty() && pq.top() < m) {
        if (pq.size() == 1) {
            cout << -1 << endl;
            return 0;
        }

        int d_least = pq.top();
        pq.pop();
        int d_second_least = pq.top();
        pq.pop();

        int new_density = d_least + 2 * d_second_least;

        pq.push(new_density);
        operations++;
    }

    cout << operations << endl;

    return 0;
}