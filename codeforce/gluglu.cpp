//
// Created by kaloyyyyy on 13/02/2023.
//
#include  <iostream>
#include  <bits/stdc++.h>
#include <string>
using namespace std;

struct node {
    string word;
    char first;
    char last;
    int *next;
};

int main() {
    struct node *head;;
    string alpha = " abcdefghijklmnopqrstuvwxyz";
    map<char, int> alphabets;

    for (int i = 1; i <= 26; i++) {
        alphabets.insert({alpha[i], i});
    }

    int i = 0, t = 0, n = 0, m = 0;
    cin >> n >> m;
    // declare string variables
    string S, T;
    cin.ignore();
    // use getline() function to read a line of string and store into S variable.
    getline(cin, S);
    // X is an object of stringstream that references the S string
    stringstream X(S);

    while (getline(X, T, ' ')) {
        node current = *head;
        if(head == nullptr){
            node newNode;
            newNode.word = T;
            newNode.first = T[0];
            newNode.last = T[T.size()-1];
            newNode.next = nullptr;
            head = &newNode;
            current = newNode.next;
        }else{
            node newNode;
            newNode.word = T;
            newNode.first = T[0];
            newNode.last = T[T.size()-1];
            newNode.next = nullptr;

        }
    }

    for (i = 0; i < n; i++) {
        cout << words[i][0] << "\n";
    }

}
