#include <bits/stdc++.h>
using namespace std;
long long a, n;
//priority_queue<long long, vector<long long>, greater<>> arr;
set<long long> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a;
    int count = 0;
    long long value = n;
    long long sValue = ((n / 2) * n ) + (a / 2);
    long long root;
    if (n == 1 && a == 0) {
        cout << "ABSOLUTELY WAY TOO MANY";
        return 10;
    }
    if (n == 0 || a == 0) {
        cout << 0 << "\n";
        return 100;
    }
    if (n == 1 && a == 1) {
        cout << 1 << "\n" << 1;
        return 11;
    }
    if (n < a) {
        cout << 0 << "\n";
        return 111;
    }
    do {
        root = (1 + sqrt(1 - (4 * (a - value)))) / 2;
        if ((root * root + a) == value + root) {
            arr.insert(root);
            arr.insert(n - root + 1);
        }
        root = (1 + sqrt(1 - (4 * (a - sValue)))) / 2;
        if ((root * root + a) == value + root) {
            arr.insert(root);
            arr.insert(n - root + 1);
        }
        value = value + n;
        sValue = sValue - n;
    } while (sValue > value);
    if (count * 2 <= 100000) {
        cout << arr.size() << "\n";
        for (long long i: arr) {
            cout << i << "\n";
        }
    } else {
        cout << "ABSOLUTELY WAY TOO MANY";
    }
    return 0;
}