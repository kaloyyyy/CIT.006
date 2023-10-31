#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, count = 0;
    string input;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>input;
        if(input[1]=='-'){
            count--;
        }else{
            count++;
        }
    }
    cout<<count;
}