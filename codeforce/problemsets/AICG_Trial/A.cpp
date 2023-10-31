#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) { res = res * a % p; }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
cin>>x;
    if (x%2==0 && x>2){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}