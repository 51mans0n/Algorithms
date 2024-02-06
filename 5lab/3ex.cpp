#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> rows(n);
    for (int i = 0; i < n; i++) { 
        cin >> rows[i];
    }
    
    sort(rows.begin(), rows.end(), greater<int>());
    long long revenue = 0;
    int max_element = rows[0];
    while(x > 0){
    x -= count(rows.begin(),rows.end(),max_element);
    revenue += count(rows.begin(),rows.end(),max_element) * max_element;
    for_each(rows.begin(), rows.end(), [max_element](int &element) {
        if (element == max_element) {
            element--;
        }
    });
    max_element--;
    }
    cout << revenue - (max_element + 1) * abs(x);
    return 0;
}
