#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr;
    map<int, int> m;
    int n, k, oneCount=0, twoCount = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        arr.push_back(k);
        if(k==1)oneCount++;
        if(k==2)twoCount++;
        if(isPrime(k) && k > 2){
            arr[i]=1;
        }else if (isPrime(k/2) && k>2){

        }
    }

    for (int i = 0; i < n; i++) {
        int ctr = 0;
        if (m.find(arr[i]) != m.end()) {
            cout << m[arr[i]] << " ";
        }else if(arr[i]==2){
            cout<<twoCount+oneCount-1<<" ";
        } else {
            for (int j = 0; j < n; j++) {
                if (arr[i] % arr[j] == 0 && i != j) {
                    ctr++;
                }
            }
            m.insert({arr[i], ctr});
            cout << ctr << " ";
        }
    }
    return 0;
}

bool isPrime(int x) {
    if(x<2) return false;
    for(int n = 2;n*n<=x;n++){
        if(x%n == 0)return false;
    }
    return true;
}
