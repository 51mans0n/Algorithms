#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int BASE = 11;

int calculateHash(const string& s) {
    long long hash = 0;
    long long power = 1;

    for (char c : s) {
        int digit = c;
        hash = (hash + (digit - 47) * power) % MOD;
        power = (power * BASE) % MOD;
    }

    return hash;
}

int main() {
    int N;
    cin >> N;
    unordered_set<string> hashSet;
    vector<pair<string, string>> normalizator;

    for (int i = 0; i < 2 * N; i++) {
        string input;
        cin >> input;
        string hash = to_string(calculateHash(input));
        hashSet.insert(input);
        normalizator.push_back({input, hash});
    }

    int cnt = 0;
    for (const auto& entry : normalizator) {
        const string& num = entry.first;
        const string& hash = entry.second;

        if (hashSet.count(hash)) {
            cout << "Hash of string \"" << num << "\" is " << hash << endl;
            cnt++;
        }
        if (cnt == N) {
            break;
        }
    }

    return 0;
}
