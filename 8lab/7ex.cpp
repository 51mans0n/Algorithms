#include <iostream>
#include <string>

using namespace std;

const int base = 29;
const int mod = 1e9 + 7;

int getHash(string str) {
    int result = 0;
    for (char c : str) {
        result = (result * base + c - 'a' + 1) % mod;
    }
    return result;
}

int findEqual(const string& mainString, const string& subString) {
    int subStringLength = subString.length();
    int mainStringLength = mainString.length();
    int subStringHash = getHash(subString);
    int count = 0;

    for (int i = 0 ; i <= mainStringLength - subStringLength ; ++i) {
        string currentSubStr = mainString.substr(i, subStringLength);
        int currentSubStrHash = getHash(currentSubStr);
        if (currentSubStrHash == subStringHash) {
            if (currentSubStr == subString) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    string myStr; cin >> myStr;
    int val; cin >> val;
    int array[val];
    for (int i = 0 ; i < val ; i++) {
        int temp1; cin >> temp1;
        int temp2; cin >> temp2;
        string substr = myStr.substr(temp1 - 1, temp2 - temp1 + 1);
        int count = findEqual(myStr, substr);
        array[i] = count;
    }
    for (int i : array) {
        cout << i << endl;
    }
}