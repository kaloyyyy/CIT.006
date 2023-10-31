#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        int n,x,p, sum;
        cin>>n>>x>>p;
        bool notfind = true;
        sum = p*(p+1)/2;
        int test = abs(n - x);
        if(n==0){
            cout<<"NO\n";
            continue;
        }
        if (is_prime(test) && test>3){
            cout<<"NO\n";
            continue;
        }
        if (p==1){
            if(x+1==n){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            continue;
        }
        if (n>sum+x){
            notfind = true;
        }else {
            for (int i = 1; i <= p; i++) {
                sum = i * (i + 1) / 2;
                if (sum > n) {
                    sum = sum %n;
                }
                if (abs(sum) == abs(n - x)) {
                    cout << "YES\n";
                    notfind = false;
                    break;
                }
            }
        }
        if (notfind){
            cout<<"NO\n";
        }
    }
}