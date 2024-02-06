#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shuffleToBalancedBST(vector<int>& arr, int left, int right, vector<int>& result) {
    if (left > right) {
        return;
    }

    int mid = (left + right) / 2;
    result.push_back(arr[mid]); 
    shuffleToBalancedBST(arr, left, mid - 1, result);
    shuffleToBalancedBST(arr, mid + 1, right, result);
}

int main() {
    int N;
    cin >> N;

    int numElements = (1 << N) - 1; 
    vector<int> arr(numElements);

    for (int i = 0; i < numElements; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int> result; 
    shuffleToBalancedBST(arr, 0, numElements - 1, result);

    for (int i = 0; i < numElements; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}