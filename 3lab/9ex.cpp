#include <iostream>
#include <vector>

using namespace std;
bool binarySearch(vector<int> myVec, int number) {
    int left = 0;
    int right = myVec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (myVec[mid] == number) {
            return true;
        }
        else if (myVec[mid] < number) {
            left = mid + 1;
        }
        else if (myVec[mid] > number) {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int size;
    cin >> size;
    vector<int> myVec(size);
    for (int i = 0 ; i != myVec.size() ; i++) {
        cin >> myVec[i];
    }
    int number;
    cin >> number;
    bool result = binarySearch(myVec, number);
    if (result) {
        cout << "Yes";
    }
    else cout << "No";
}