#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> block_sizes(N);
    for (int i = 0; i < N; i++) {
        cin >> block_sizes[i];
    }

    vector<int> prefix_sum(N);
    prefix_sum[0] = block_sizes[0];
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + block_sizes[i];
    }

    vector<int> mistakes(M);
    for (int i = 0; i < M; i++) {
        cin >> mistakes[i];
    }

    for (int i = 0; i < M; i++) {
        int left = 0, right = N - 1;
        int mistake_line = mistakes[i];

        while (left <= right) {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] >= mistake_line) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << left + 1 << endl; 
    }

    return 0;
}