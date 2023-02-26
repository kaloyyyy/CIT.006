#include <iostream>
#include <map>
using namespace std;

map<int, int> prime_factors(int n) {
    map<int, int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

long long count_trailing_zeroes(long long n, long long m) {
    map<int, int> factors = prime_factors(m);
    long long count = 1e15;
    for (auto & factor : factors) {
        long long p = factor.first;
        long long exp = factor.second;
        long long factor_count = 0;
        long long temp = n;
        while (temp > 0) {
            temp /= p;
            factor_count += temp;
        }
        count = min(count, factor_count / exp);
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        if (m > 1 && n>0) {
            if (n != 0) {
                long long count = count_trailing_zeroes(n, m);
                cout << count << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else if(m==0) {
            cout<< 1 << "\n";
        }
        else if(m==1 || n==1) {
            cout << 0 << "\n";
        }
    }

return 0;
}
