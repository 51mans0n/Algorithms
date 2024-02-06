#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);

    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }

    char target;
    cin >> target;

    char balanced_char = chars[0];

    for (int i = 0; i < n; ++i) {
        if (chars[i] > target) {
            balanced_char = chars[i];
            break;
        }
    }

    cout << balanced_char << endl;

    return 0;
}