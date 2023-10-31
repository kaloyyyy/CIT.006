#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b;
    cin>>a>>b;
    int count = 0;
    do{
        a*=3;
        b*=2;
        count++;
    }while(a<=b);
    cout<<count;
}