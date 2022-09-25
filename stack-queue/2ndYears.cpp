//
// Created by kaloyyyyy on 11/08/2022.
//
#include <iostream>
using namespace std;
int main(){
    int temp = 0, curr = 0, prev = 0, input;
    bool found = false;
    cout<<"input number\n";
    cin>>input;
    while(!found){
        cout<<"current number: "<<curr<<endl;
        if(curr == input){
            cout<<input<<" is part of the fibonacci sequence\n";
            found = true;
        }else if (curr > input){
            cout<<"input number is not a part of the fibonacci sequence\n";
            found = true;
        }else{
            temp = prev;
            prev = curr;
            curr = curr + temp;
            if(curr == 0){
                curr = 1;
            }
        }
    }
}