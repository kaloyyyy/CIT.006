#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin>>n;
        vector<int>high;
        int highCount = 0;
        int lowCount = 0;
        vector<int>low;
        for (int j = 0; j < n; j++) {
            int x;
            cin>>x;
            if (x>0){
                highCount++;
            }else if(x<0){
                lowCount++;
            }
        }
        int j = 1;
        for (; j <= highCount; j++) {
            cout<<j<<" ";
        }
        j--;
        for (int k=0; k < lowCount; k++) {
            j--;
            cout<<j<<" ";
        }
        cout<<"\n";
        int half = lowCount;
        for (int k = 0; k < half; k++) {
            cout<<1<<" "<<0<<" ";
        }
        for (int k = 1; k <=highCount-half; k++) {
            cout<<k<<" ";
        }
        cout<<"\n";
    }
}