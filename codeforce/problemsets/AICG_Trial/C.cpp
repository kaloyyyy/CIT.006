#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, count = 0, x,y,z;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >>x>>y>>z;
        if (x+y+z>=2){
            count++;
        }
    }
    cout<<count;
}