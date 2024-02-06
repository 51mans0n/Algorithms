#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> hashes(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> hashes[i];
    }

    string S = "";
    long long prev_hash = 0;

    for (int i = 0; i < N; ++i) {
        long long current_hash = hashes[i] - prev_hash;
        char c = current_hash / (1LL << i) + 'a';
        S += c;
        prev_hash += (c - 'a') * (1LL << i);
    }

    cout << S << endl;
    
    return 0;
}