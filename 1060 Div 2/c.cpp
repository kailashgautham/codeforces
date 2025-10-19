#include <bits/stdc++.h>
using namespace std;

bool factor_finder(int n, set<int>& factors, set<int>& new_factors) {
    if (n <= 1) return false;
    int factors_found = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors_found++;
            int j = n / i;
            if (factors.contains(i) || factors.contains(j)) return true;
            new_factors.insert(i);
            new_factors.insert(j);
        }
    }
    if (factors_found == 0) new_factors.insert(n);
    return false;
}

int check_direction(vector<int>& a, int n) {
    int best_ans = 2;
    set<int> factors;
    set<int> plus_minus;
    for (int i = n - 1; i >= 0; i--) {

        set<int> new_factors;
        set<int> new_plus_minus;

        if (factor_finder(a[i], factors, new_factors)) {
            best_ans = 0;
            break;
        }

        if (factor_finder(a[i], plus_minus, new_factors)) {
            best_ans = min(best_ans, 1);
        }

        if (factor_finder(a[i] + 1, factors, new_plus_minus)) {
            best_ans = min(best_ans, 1);
        }

        if (factor_finder(a[i] + 1, plus_minus, new_plus_minus)) {
            best_ans = min(best_ans, 2);
        }

        if (factors.contains(a[i]) && a[i] != 1) best_ans = 0;

        if (factors.contains(a[i] + 1)) best_ans = min(best_ans, 1);

        if (plus_minus.contains(a[i])) best_ans = min(best_ans, 1);

        if (plus_minus.contains(a[i] + 1)) best_ans = min(best_ans, 2);

        factors.insert(a[i]);
        plus_minus.insert(a[i] + 1);

        factors.insert(new_factors.begin(), new_factors.end());
        plus_minus.insert(new_plus_minus.begin(), new_plus_minus.end());

        if (i == 0) best_ans = min(best_ans, 2);
    }
    return best_ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {

        // Input
        int n; cin >> n;
        vector<int> a;
        int even = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x; a.push_back(x);
            if (x % 2 == 0) even++;
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
        }

        int best_ans = 2;
        if (even > 1) best_ans = 0;
        else {
            sort(a.begin(), a.end());
            best_ans = min(best_ans, check_direction(a, n));
        }
        cout << best_ans << endl;
    }
}