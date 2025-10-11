#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s[x]++;
    }

    int total_amt = 0;
    int edge_count = 0;
    std::erase_if(s, [&total_amt, &edge_count](auto &item) {
      auto &[edge, count] = item;
      int even_edges = 2 * (count / 2);
      total_amt += (even_edges * edge);
      edge_count += even_edges;
      count -= even_edges;
      return count == 0;
    });

    if (edge_count == 0) {
      cout << 0 << endl;
      continue;
    }

    int ans = edge_count == 2 ? 0 : total_amt;

    for (auto it = s.begin(); it != s.end(); ++it) {
      auto &[edge, count] = *it;
      if (count == 0)
        continue;
      if (edge < total_amt)
        ans = max(ans, total_amt + edge);
      if (std::next(it) == s.end())
        continue;
      auto &[new_edge, new_count] = *std::next(it);
      if (new_edge < (total_amt + edge) && new_count > 0)
        ans = max(ans, total_amt + edge + new_edge);
    }

    cout << ans << endl;
  }
}