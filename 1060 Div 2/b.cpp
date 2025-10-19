#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a;
        vector<int> pref(n, 0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x; a.push_back(x);
        }
        pref[0] = a[0];
        for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], a[i]);
        for (int i = 1; i < n; i += 2) a[i] = pref[i];
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            if (i % 2 == 0 && i + 1 < n && a[i] >= a[i + 1]) {
                ans += (a[i] - a[i + 1] + 1);
                a[i] = a[i + 1] - 1;
            } else if (i % 2 == 1 && i + 1 < n && a[i] <= a[i + 1]) {
                ans += (a[i + 1] - a[i] + 1);
                a[i + 1] = a[i] - 1;
            }
        }
        cout << ans << endl;
     }
}