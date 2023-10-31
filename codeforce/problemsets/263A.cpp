#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin>>x;
            if (x == 1){
                x = abs( j-2) + abs( i - 2);
                cout<<x;
                return 0;
            }
        }
    }
}