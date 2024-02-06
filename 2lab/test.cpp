#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int calculateHash(const string& s) {
    long long hash = 0;
    long long power = 1;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        int digit = s[i];
        hash = (hash + (digit - 47) * power) % MOD;
        power = (power * 11) % MOD;
    }

    return hash;
}

int main() {
    int N;
    cin >> N;
    unordered_multiset<string> hashSet;
    vector<string> order(2*N);
    for(int i = 0;i < 2*N;++i){
        string input;cin >> input;
        hashSet.insert(input);
        order[i] = input;
    }
    for (int i = 0; i < 2 * N; ++i) {
        string hash;
        hash = to_string(calculateHash(order[i]));
        auto it = hashSet.find(hash);
        if (it != hashSet.end()) {
            cout << "Hash of string \"" << order[i] << "\" is " << hash << endl;
            it = hashSet.erase(it);
            i--;
        }
    }

    return 0;
}