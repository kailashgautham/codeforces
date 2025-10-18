#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    set<int> s;
    int mex = 0;
    while (n--) {
        int x; cin >> x;
        s.insert(x);
        while (s.contains(mex)) mex++;
    }
    cout << mex << endl;
  }
}