#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int count = 0, min = 0, cons = 1;
    char c;
    while(n--){
        char prev;
        string input;
        cin>>input;
        for (char c : input) {
            if (prev == '0' && min>0 && c=='1'){
                min++;
            }
            if(c=='1'){
                count++;
                if (min==0){
                    min++;
                }
                if (prev == '1'){
                    cons ++;
                    if (cons > m/4 && cons < m/2){
                        min++;
                        cons = 1;
                    }
                }else{
                    cons = 1;
                }
            }
            prev = c;
        }
    }
    cout<<min<<" "<<count<<"\n";
}