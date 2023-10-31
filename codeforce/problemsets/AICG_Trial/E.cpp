#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    char curr;
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(curr == s[i]){
            count++;
            if(count == 7){
                cout<<"YES";
                break;
            }
        }else{
            curr = s[i];
            count = 1;
        }
    }
    if(count != 7){
        cout<<"NO";
    }
}