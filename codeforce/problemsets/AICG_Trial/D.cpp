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

    // Code goes here
    int n;
    string s1, s2;
    cin>>n;
    map<char,int>equivalent;
    equivalent.insert(mp('S',-1));
    equivalent.insert(mp('M',0));
    equivalent.insert(mp('L',1));
    while(n--){
        cin>>s1>>s2;
        char last1 = s1[s1.size()-1];
        char last2 = s2[s2.size()-1];
        int value1 = equivalent[last1];
        int value2 = equivalent[last2];
        value1 = value1*s1.size();
        value2 = value2*s2.size();

        if (value1>value2){
            cout<<">\n";
        }else if(value1<value2){
            cout<<"<\n";
        }else{
            cout<<"=\n";
        }
    }
    return 0;
}