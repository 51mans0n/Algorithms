#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> max_heap;

    for (int stone : stones) {
        max_heap.push(stone);
    }

    while (max_heap.size() > 1) {
        int y = max_heap.top();
        max_heap.pop();
        int x = max_heap.top();
        max_heap.pop();

        if (x != y) {
            max_heap.push(y - x);
        }
    }

    if (max_heap.empty()) {
        return 0;
    } else {
        return max_heap.top();
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> stone_weights(N);

    for (int i = 0; i < N; ++i) {
        cin >> stone_weights[i];
    }

    int result = lastStoneWeight(stone_weights);
    cout << result << endl;

    return 0;
}