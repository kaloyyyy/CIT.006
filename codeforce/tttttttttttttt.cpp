#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<string, int> starPrice;
    int *starPtrVal[10000];
    map<string, int*> starPtr;
    map<string,map<string, int>> recipe;
    int N, Q, R;
    cin >> N >> Q >> R;
    string temp, reciTemp;
    int value;
    for (int i = 0; i < N; i++) {
        cin >> temp >> value;
        starPrice.insert(make_pair(temp, value));
        starPtr.insert({temp,&starPrice[temp]});
    }
    for (int i = 0; i < Q; i++) {
        cin >> temp >> reciTemp >> value;
    }


    for ( auto& [k1, v1] : recipe)
        for ( auto& [k2, v2] : v1)
            std::cout << "m[" << k1 << "][" << k2 << "]=" << v2 << std::endl;
}