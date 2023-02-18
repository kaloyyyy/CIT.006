#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    int r = 0;
    cin>>x;
    for(x; x!=0; x/=3){
        cout<<x<<"\t"<<x%3<<"\n";
        r += (x%3);
    }
    cout<<r;
}