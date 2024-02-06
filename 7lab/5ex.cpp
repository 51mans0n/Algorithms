#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareRows(const vector<int>& row1, const vector<int>& row2) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < row1.size(); ++i) {
        sum1 += row1[i];
        sum2 += row2[i];
    }

    if (sum1 != sum2) {
        return sum1 > sum2;
    } else {
        for (int i = 0; i < row1.size(); ++i) {
            if (row1[i] != row2[i]) {
                return row1[i] < row2[i];
            }
        }
        return false; 
    }
}

void merge(vector<vector<int>>& rows, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> leftArr(n1, vector<int>(rows[0].size()));
    vector<vector<int>> rightArr(n2, vector<int>(rows[0].size()));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < rows[0].size(); ++j) {
            leftArr[i][j] = rows[left + i][j];
        }
    }
    for (int j = 0; j < n2; j++) {
        for (int k = 0; k < rows[0].size(); ++k) {
            rightArr[j][k] = rows[mid + 1 + j][k];
        }
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (compareRows(leftArr[i], rightArr[j])) {
            for (int x = 0; x < rows[0].size(); ++x) {
                rows[k][x] = leftArr[i][x];
            }
            i++;
        } else {
            for (int x = 0; x < rows[0].size(); ++x) {
                rows[k][x] = rightArr[j][x];
            }
            j++;
        }
        k++;
    }

    while (i < n1) {
        for (int x = 0; x < rows[0].size(); ++x) {
            rows[k][x] = leftArr[i][x];
        }
        i++;
        k++;
    }

    while (j < n2) {
        for (int x = 0; x < rows[0].size(); ++x) {
            rows[k][x] = rightArr[j][x];
        }
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& rows, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(rows, left, mid);
        mergeSort(rows, mid + 1, right);

        merge(rows, left, mid, right);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> rows[i][j];
        }
    }

    mergeSort(rows, 0, n - 1);

    for (const vector<int>& row : rows) {
        for (int i = 0; i < m; ++i) {
            cout << row[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
