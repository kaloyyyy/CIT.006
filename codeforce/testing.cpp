#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n = 14, a = 2;
    set<int>primeOfn;
    primeOfn.insert(1);
    primeOfn.insert(2);
    primeOfn.insert(7);
    for (auto x: primeOfn) {
        for (int j = 0; j <= x; j++) {
            if((j*j - j + a)%x == 0){
                cout<<j<<" ";
            }
        }
    }
}