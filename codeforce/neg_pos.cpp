#include  <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        long long sum = 0;
        int neg = 0, ind = 0;
        vector<int> a;
        int i, n = 0, k;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> k;
            a.push_back(k);
        }

        for (i = 0; i < a.size(); i++) {
            if (a[ind] > abs(a[i])) {
                ind = i;
            }
            if (a[i] < 0) {
                a[i] = abs(a[i]);
                neg++;
            } else if (a[i] == 0) {
                neg = -1;
                break;
            }
        }
        if (neg == -1 || neg % 2 == 0) {
            for (auto x: a) {
                sum = sum + abs(x);
            }
        } else {
            a[ind] = -abs(a[ind]);
            for (auto x: a) {
                sum = sum + x;
            }
        }
        cout << sum << "\n";
    }
}