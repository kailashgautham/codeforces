#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, vector<int>> adj;
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

    }
}