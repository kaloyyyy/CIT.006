#include <bits/stdc++.h>
using namespace std;

// To find the power of a prime p in
// factorial N
unsigned int findPowerOfP(unsigned long int N, unsigned int p)
{
    unsigned int count = 0;
    unsigned long long int r = p;
    while (r <= N) {
        count += (N / r);
        // increasing the power of p
        // from 1 to 2 to 3 and so on
        r = r * p;

    }

    return count;
}

// returns all the prime factors of k
vector<pair<unsigned int, unsigned int> > primeFactorsofB(unsigned int B)
{
    // vector to store all the prime factors
    // along with their number of occurrence
    // in factorization of B
    vector<pair<unsigned int, unsigned int> > ans;

    for (unsigned int i = 2; B != 1; i++) {
        if (B % i == 0) {
            unsigned int count = 0;
            while (B % i == 0) {
                B = B / i;
                count++;
            }

            ans.push_back(make_pair(i, count));
        }
    }
    return ans;
}

// Returns largest power of B that
// divides N!
unsigned long int largestPowerOfB(unsigned long int N, unsigned int B)
{
    vector<pair<unsigned int, unsigned int> > vec;
    vec = primeFactorsofB(B);
    unsigned int ans = INT_MAX;
    for (unsigned int i = 0; i < vec.size(); i++)

        // calculating minimum power of all
        // the prime factors of B
        ans = min(ans, findPowerOfP(N,
                                    vec[i].first)
                       / vec[i].second);

    return ans;
}

// Driver code
int main()
{
    unsigned long int value = 734206856189756;
    unsigned int base = 848279527;
    cout<<"Value: "<<value<<endl;
    cout<<"Base: "<<base<<endl;
    cout << largestPowerOfB(value, base) << endl;
    return 0;
}