// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
#include <pthread_time.h>
using namespace std;

// Driver Code
int main() {
    int low, high;
    int count;
    cin >> low >> high;
    count = high - low + 1;
    count = count / 2;
    if ((low / 2) * 2 != low && ((high / 2) * 2 != high)){
        cout<<"both odd";
        count ++;
    }
    cout<<count;
    return 0;
}

