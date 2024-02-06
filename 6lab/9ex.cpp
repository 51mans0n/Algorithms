#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string& s) {
    int n = s.length();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] > s[i]) {
                swap(s[i - 1], s[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    string input;
    cin >> input;

    bubbleSort(input);

    cout << input << endl;

    return 0;
}