#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        int prev_k = 0;
        k--;
        for (int i = 0; i < n; i++) {
            if (i - k - 1 >= 0 && s[i - k - 1] == '1') prev_k--;
            if (s[i] == '0') continue;
            if (prev_k == 0) ans++;
            prev_k++;
        }
        cout << ans << endl;
    }
}