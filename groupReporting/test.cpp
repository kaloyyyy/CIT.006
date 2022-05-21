//
// Created by kaloyyyyy on 20/05/2022.
//
#include <iostream>
using namespace std;


int main() {
    //declare variables for the input
    int sieve10, sieve40, sieve200, liquidL, plasticL;
    cout << "input sieve no.200\n";
    cin >> sieve200;
    if (sieve200 > 35) {
        //finding A-4 and above
        cout << "input liquid limit\n";
        cin >> liquidL;
        cout << "input Plasticity limit\n";
        cin >> plasticL;
        if (liquidL > 40) {
            if (plasticL > 10) {
                //A-7 etc etc
                cout << "A-7\n";
            } else {
                //A-5
                cout << "A-5\n";
            }
        } else {
            if (plasticL > 10) {
                //A-6
                cout << "A-6\n";
            } else {
                //A-4
                cout << "A-4\n";
            }
        }
    } else if (sieve200 > 25) {

        cout << "input liquid limit\n";
        cin >> liquidL;
        cout << "input Plasticity limit\n";
        cin >> plasticL;
        if (liquidL > 40) {
            if (plasticL > 10) {
                //A-2-7
                cout << "A-2-7\n";
            } else {
                //A-2-5
                cout << "A-2-5\n";
            }
        } else {
            if (plasticL > 10) {
                //A-2-6
                cout << "A-2-6\n";
            } else {
                //A-2-4
                cout << "A-2-4\n";
            }
        }
    } else {
        // finding A-1 or A-3
        cout << "enter sieve no. 40\n";
        cin >> sieve40;
        if (sieve40 > 50) {
            //A-3
            cout << "A-3\n";
        } else if (sieve40 > 30) {
            //A-1-b
            cout << "A-1-b\n";
        } else {
            //A-1-a
            cout << "A-1-a\n";
        }
    }
}
