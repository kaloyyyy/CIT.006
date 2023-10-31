#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        x = abs(x);
        y = abs(y);
        int diff, move=0, diag = 0;
        if (x > y){
            diff = x - y;
            move = (diff*2) - 1;
            if (y>0){
                diag = y*2;
            }
        }else if(x < y){
            diff = y - x;
            move = (diff*2) - 1;
            if (y>0){
                diag = x*2;
            }
        }else if (x==y){
            move = x+y;
        }
        cout<<diag+move<<"\n";
    }
}