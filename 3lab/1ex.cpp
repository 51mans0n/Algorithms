#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> elements(t);

    for (int i = 0; i < t; ++i) {
        cin >> elements[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    unordered_map<int, pair<int, int>> element_to_coordinates;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            element_to_coordinates[matrix[i][j]] = {i, j};
        }
    }

    for (int i = 0; i < t; ++i) {
        if (element_to_coordinates.find(elements[i]) != element_to_coordinates.end()) {
            pair<int, int> coordinates = element_to_coordinates[elements[i]];
            cout << coordinates.first << " " << coordinates.second << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}