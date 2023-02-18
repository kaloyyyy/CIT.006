#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        int D, W, B;
        cin>>D>>W>>B;
        if ((2*W*B/2)+W>=D)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}