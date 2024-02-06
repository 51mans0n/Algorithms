#include <iostream>
#include <unordered_set>

using namespace std;

size_t hashString(const string& str) {
    size_t hash = 0;
    for (char c : str) {
        hash = (hash * 31) + c; 
    }
    return hash;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();
    unordered_set<size_t> substrings;

    for (int i = 0; i < n; i++) {
        size_t hash = 0;
        for (int j = i; j < n; j++) {
            hash = (hash * 31) + s[j]; 
            substrings.insert(hash);   
        }
    }

    cout << substrings.size() << endl;

    return 0;
}