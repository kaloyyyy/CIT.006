#include <bits/stdc++.h>
using namespace std;
long long a, n;
long long gAlt(long long seed) {
    long long x = a + (seed * seed);
    long long y = (x / n);
    return x - n * (y);
}
long long gRecursive(long long seed){
    long long answer = gAlt(seed);
    if (seed == answer){
        return answer;
    }
    return -1;
}
int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<long long>arr;

    for(int j = 0; j<100; j++){
        cin>>n>>a;

        int count = 0;
        long long end = n;
        for (long long i = 0; i < end; i++) {
            long long x = gRecursive(i);
            if (x == i) {
                //cout << "\neto may number y e y " << i << endl;
                count++;
                arr.push_back(x);
                cout<<x<<" ";
            }
        }
        cout<<"set "<<a<<"  count ";
        cout << count << "\n";

    }
}