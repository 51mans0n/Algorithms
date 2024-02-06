#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> firstArray(n);
    vector<int> secondArray(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> firstArray[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> secondArray[i];
    }
    
    unordered_map<int, int> countMap;
    
    for (int num : firstArray) {
        countMap[num]++;
    }
    
    vector<int> commonNumbers;
    
    for (int num : secondArray) {
        if (countMap.find(num) != countMap.end() && countMap[num] > 0) {
            commonNumbers.push_back(num);
            countMap[num]--;
        }
    }
    sort(commonNumbers.begin(),commonNumbers.end());
    for (int i = 0; i < commonNumbers.size(); ++i) {
        cout << commonNumbers[i];
        if (i < commonNumbers.size() - 1) {
            cout << " ";
        }
    }
    
    return 0;
}