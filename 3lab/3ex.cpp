#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < q; j++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (l1 <= a[i] && a[i] <= r1) {
                count++;
            } else if (l2 <= a[i] && a[i] <= r2) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}