#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x=0, y=0, z=0;
    cin>>n;
    while (n--){
        int ix, iy, iz;
        cin>>ix>>iy>>iz;
        x+=ix;
        y+=iy;
        z+=iz;
    }
    if (x == 0 && y == 0 && z == 0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}