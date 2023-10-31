#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, n ,w, cost = 0;
    cin>>k>>n>>w;
    for (int i = 1; i <=w; i++) {
        cost = cost + k*i;
    }
    if (cost<=n){
        cout<<0;
    }else{
        cout<<cost-n;
    }
}