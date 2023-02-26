#include <bits/stdc++.h>
using namespace std;
int mainArr[5000000];
int counterArr[5000000];
set<int>checkArr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        cin>>mainArr[i];
        counterArr[mainArr[i]]++;
        checkArr.insert(mainArr[i]);
    }
    auto end = std::chrono::high_resolution_clock::now(); // get the current time again
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_time).count(); // calculate the time difference in ms
    cout << "Time taken: " << duration << " ms" << std::endl; // print the time taken

}