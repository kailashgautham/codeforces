#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      b.push_back(c);
    }
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || b[i] != b[i - 1])
        ans++;
    }
    cout << ans << endl;
  }
}