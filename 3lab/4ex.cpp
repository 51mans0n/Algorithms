#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    while (q--) {

        int l1, r1, l2, r2;
        int ans = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1){
        auto it1 = lower_bound(a.begin(), a.end(), l1);
        auto it2 = upper_bound(a.begin(), a.end(), r1);
        ans += it2 - it1;
        it1 = lower_bound(a.begin(), a.end(), l2);
        it2 = upper_bound(a.begin(), a.end(), r2);
        ans += it2 - it1;
        }else{
            l1 = min(l1,l2);
            r1 = max(r1,r2);
            auto it1 = lower_bound(a.begin(), a.end(), l1);
            auto it2 = upper_bound(a.begin(), a.end(), r1);
            ans += it2 - it1;
        }
        cout << ans << endl;
       
    }

    return 0;
}