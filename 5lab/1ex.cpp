#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long cost = 0;

    while (pq.size() > 1) {
        long long array1 = pq.top();
        pq.pop();
        long long array2 = pq.top();
        pq.pop();
        long long merged_length = array1 + array2;
        cost += merged_length;
        pq.push(merged_length);
    }

    cout << cost << endl;

    return 0;
}