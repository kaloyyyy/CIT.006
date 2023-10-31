#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int c;
    int odd = 0, even = 0, i = 0;
    for (int j = 0; j < n; j++) {
        cin>>n;
        if(n%2==0){
            even++;
        }else{
            odd++;
        }
    }
}