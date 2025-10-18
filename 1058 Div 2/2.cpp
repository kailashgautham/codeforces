#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n; cin >> n;
        vector<long long> b;
        while (n--) {
            long long i; cin >> i; b.push_back(i);
        }
        long long curr_num = 1;
        vector<long long> a(b.size(), curr_num);
        for (long long i = 1; i < a.size(); i++) {
            long long diff = b[i] - b[i - 1];
            if (i - diff >= 0) a[i] = a[i - diff];
            else a[i] = ++curr_num;
        }
        for (long long i : a) cout << i << " ";
        cout << endl;
    }
}

