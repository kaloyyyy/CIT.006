#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double weight, acce, density, projArea, drag;
    cin>>weight>>acce>>density>>projArea>>drag;
    double answer = sqrt((2*weight*acce)/(density*projArea*drag));
    cout<<answer;
}