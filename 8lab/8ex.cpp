#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string findLongestCommonSubstring(const vector<string>& strings) {
    if (strings.empty()) {
        return "";
    }

    int numStrings = strings.size();
    sort(strings.begin(), strings.end());

    int minLength = strings[0].length();
    int maxLength = strings[numStrings - 1].length();

    int low = 0, high = minLength;

    string result = "";

    while (low <= high) {
        int mid = low + (high - low) / 2;
        string candidate = strings[0].substr(0, mid);

        bool allContain = all_of(strings.begin(), strings.end(), [&](const string& s) {
            return s.find(candidate) != string::npos;
        });

        if (allContain) {
            result = candidate;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int numStrings;
    cin >> numStrings;

    vector<string> strings(numStrings);

    for (int i = 0; i < numStrings; ++i) {
        cin >> strings[i];
    }

    string result = findLongestCommonSubstring(strings);

    cout << result << endl;

    return 0;
}
