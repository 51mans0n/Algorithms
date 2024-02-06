#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    int min_length = n + 1;

    for (int left = 0; left < n; ++left) {
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), prefix_sum[left] + k);
        if (it != prefix_sum.end()) {
            int right = it - prefix_sum.begin();
            min_length = min(min_length, right - left);
        }
    }

    return (min_length <= n) ? min_length : 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minSubarrayLength(nums, k);
    cout << result << endl;

    return 0;
}