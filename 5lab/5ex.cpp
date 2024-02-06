#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    long long sum = 0;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long n;
            cin >> n;
            minHeap.push(n);
            sum += n;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
        } else if (command == "print") {
            cout << sum << endl;
        }
    }

    return 0;
}