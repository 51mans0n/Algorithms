#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(string pattern) {
    int len = 0; 
    vector<int> lps(pattern.length(), 0);

    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmpSearch(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    int m = pattern.length();
    int n = text.length();
    vector<int> occurrences;

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            occurrences.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << occurrences.size() << endl;
    for (int idx : occurrences) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    string s1, s2;
    cin >> s2 >> s1;

    kmpSearch(s2, s1);

    return 0;
}