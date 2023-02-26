#include <bits/stdc++.h>
using namespace std;

const int N = 5000000;
int arr[N], freq[N];
bool prime[350001];
void SieveOfEratosthenes()
{
    int n = 350000;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        int ctr = 0;
        int lim = sqrt(arr[i]);
        for (int j = 1; j <= lim; j++) {
            if (arr[i] % j == 0) {
                ctr += freq[j];
                if (j != arr[i] / j) {
                    ctr += freq[arr[i] / j];
                }
            }
        }
        cout << ctr - 1 << " ";
    }
    return 0;
}