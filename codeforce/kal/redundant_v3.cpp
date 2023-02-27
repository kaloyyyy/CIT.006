#include <bits/stdc++.h>
using namespace std;
int arr[5000000] = {0};
int counterArr[5000000] = {0};
int memoCheck[5000000] = {0};

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isSemiPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && isPrime(i) && isPrime(n / i)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        counterArr[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (memoCheck[arr[i]] == 0) {
            vector<int>memoCheck2(n,0);
            for (int j = 0; j < n; j++) {
                if (arr[i] % arr[j] == 0  && memoCheck2[arr[j]]==0) {
                    memoCheck[arr[i]] = memoCheck[arr[i]] + counterArr[arr[j]];
                    memoCheck2[arr[j]] = 1;
                }
            }
        }
        cout << memoCheck[arr[i]] - 1 << " ";
    }
    auto end = std::chrono::high_resolution_clock::now(); // get the current time again
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            end - start_time).count(); // calculate the time difference in ms
    std::cout << "Time taken: " << duration << " ms" << std::endl; // print the time taken
}