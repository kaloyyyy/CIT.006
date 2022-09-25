//
// Created by kaloyyyyy on 11/08/2022.
//
#include <iostream>
using namespace std;
int main(){
    int ave = 0;
    cout<<"even numbers:\n";
    for(int i = 10; i<=20; i=i+2){
        cout<<i<<", ";
        ave = ave + i;
    }
    cout<<"average: "<<(ave/6);
    ave = 0;
    cout<<"\nodd numbers: \n";
    for(int i = 11; i<=19; i=i+2){
        cout<<i<<", ";
        ave = ave + i;
    }
    cout<<"average: "<<(ave/5);
}