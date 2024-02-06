#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, P;
    cin >> N;
    vector<int> competitors(N);
    for (int i = 0; i < N; i++) {
        cin >> competitors[i];
    }
    cin >> P;
    
    for (int i = 0; i < P; i++) {
        int M;
        cin >> M;
        
        
        sort(competitors.begin(), competitors.end());
        
        int wins = 0;
        int totalPower = 0;
        
        
        for (int j = 0; j < N; j++) {
            if (competitors[j] <= M) {
                wins++;
                totalPower += competitors[j];
            } else {
                break; 
            }
        }
        
        cout << wins << " " << totalPower << endl;
    }
    
    return 0;
}