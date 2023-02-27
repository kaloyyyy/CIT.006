#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,l;
    string word, temp;
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin>>word;
        l = int(word.size());
        if (l>10){
            cout<<word[0]<<l-2<<word[l-1]<<"\n";
        }else{
            cout<<word<<"\n";
        }
    }
}