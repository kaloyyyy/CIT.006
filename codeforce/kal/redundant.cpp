#include <bits/stdc++.h>
using namespace std;

const int N = 5000000;
vector<int> arr(N);
vector<int> freq(N, 0);
vector<int> memoCnt(N, -1);


bool isPrime(int n) {

    if (n == 1) {
        return false;
    }

    int i = 2;

    while (i * i <= n) {

        if (n % i == 0) {

            return false;
        }
        i += 1;
    }
    return true;
}

set<int> getFactors(int n) {
    set<int> factors;
    for (int i = 1; i <= sqrt(n); i++) {
        int res = n % i;
        if (res == 0) {
            int b = n / i;
            factors.insert(i);
            if (b != sqrt(n)) {
                factors.insert(b);
            }
        }
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ctr;
    cin >> n;

    int x;

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        freq[arr[i]] += 1;
    }
    for (int i = 0; i < n; i++) {
        ctr = 0;
        int number = arr[i];
        if (freq[number] == n) {
            cout << n - 1 << " ";
            i = n;
            break;
        }
        if (memoCnt[number] == -1) {
            for (int j = 1; j <= sqrt(number); j++) {
                int res = number % j;
                if (res == 0) {
                    int b = number / j;
                    ctr += freq[j];
                    if (b != sqrt(number)) {
                        ctr += freq[b];
                    }
                }
            }
            memoCnt[arr[i]] = ctr - 1;
            if (number == 0) { memoCnt[arr[i]] = 0; }
        }

        cout << memoCnt[arr[i]] << " ";
    }
    return 0;
}