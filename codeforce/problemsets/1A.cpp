#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long double n,m,a;
    long long x, y;
    cin>>n>>m>>a;
    x = ceil(n/a);
    y = ceil(m/a);
    cout<<x*y;
}