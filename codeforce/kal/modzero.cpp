#include <iostream>
#include <vector>
using namespace std;

const int N = 5000000;

bool isPrime[N+1];
vector<int> primes;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ctr;
    cout<<"enter ";
    cin>>n;
    vector<int> arr(n);
    vector<int> freq(N, 0);
    vector<int>memoCnt(N,-1);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        freq[arr[i]] += 1;
        cout<<"ent "<<i<<" ";
    }
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}
