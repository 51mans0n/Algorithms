#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    while (cin >> N && N > 0) {
        vector<string> patterns(N);
        unordered_map<string, int> patternCount;
        vector<string> dominatingPatterns;

        for (int i = 0; i < N; ++i) {
            cin >> patterns[i];
        }

        string text;
        cin >> text;

        int maxCount = 0;

        for (const string& pattern : patterns) {
            int count = 0;
            size_t pos = text.find(pattern);
            while (pos != string::npos) {
                ++count;
                pos = text.find(pattern, pos + 1);
            }
            patternCount[pattern] = count;
            maxCount = max(maxCount, count);
        }

        for (const string& pattern : patterns) {
            if (patternCount[pattern] == maxCount) {
                dominatingPatterns.push_back(pattern);
            }
        }

        cout << maxCount << endl;
        for (const string& pattern : dominatingPatterns) {
            cout << pattern << endl;
        }
    }

    return 0;
}