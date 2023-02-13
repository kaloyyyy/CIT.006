//
// Created by kaloyyyyy on 13/02/2023.
//
#include  <iostream>
#include  <bits/stdc++.h>
#include <string>
using namespace std;

struct node {
    string word;
    int value;
    int *next;
};

int main() {
    string arr[10000];

    int i = 0, t = 0, n = 0, m = 0;
    cin >> n >> m;

    string S, T;  // declare string variables
    cin.ignore();
    getline(cin, S); // use getline() function to read a line of string and store into S variable.

    stringstream X(S); // X is an object of stringstream that references the S string

    while (getline(X, T, ' ')) {
        arr[i]=T;
        i++;
    }

    for (i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
/*    for (i = 0; i < 2; i++) {
        scanf("%d", &arr[i]);
    }*/
}
