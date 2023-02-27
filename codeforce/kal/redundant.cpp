#include <bits/stdc++.h>
using namespace std;
#define N 500000
int arr[N] = {0};
int counterArr[N] = {0};
int memoCheck[N] = {0};
int is_prime[N] = {1};

bool sieve(int high) {
    // We cross out all composites from 2 to sqrt(N)
    int i=2;
    // This will loop from 2 to int(sqrt(x))
    while(i*i <= high+1) {
        // If we already crossed out this number, then continue
        if(is_prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < high+1) {
            // Cross out this as it is composite
            is_prime[j] = 0;
            // j is incremented by i, because we want to cover all multiples of i
            j += i;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    auto start_time = std::chrono::high_resolution_clock::now();
    int high;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        counterArr[arr[i]]++;
        high = max(arr[i], arr[i-1]);
    }
    is_prime[0] = 0;
    is_prime[1] = 0;
    sieve(high);
    for (int i = 0; i < n; i++) {
        if (memoCheck[arr[i]] == 0) {
            bool prime = is_prime[arr[i]];
            bool semiPrime = is_prime[arr[i]/2];
            if (arr[i]==1){
                memoCheck[arr[i]] = counterArr[arr[i]];
            }else if (prime) {
                memoCheck[arr[i]] = counterArr[arr[i]] + counterArr[1];
            } else if (semiPrime) {
                memoCheck[arr[i]] = counterArr[arr[i]] + counterArr[1] + counterArr[2] + counterArr[arr[i]/2];
            } else {
                for (int j = 0; j < n; j++) {
                    if (arr[i] >= arr[j] && arr[i] % arr[j] == 0) {
                        memoCheck[arr[i]] = memoCheck[arr[i]] + counterArr[arr[j]];
                    }
                }
            }
        }
        cout << memoCheck[arr[i]] - 1 << " ";
    }
    auto end = std::chrono::high_resolution_clock::now(); // get the current time again
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_time).count(); // calculate the time difference in ms
    std::cout << "Time taken: " << duration << " ms" << std::endl; // print the time taken
}