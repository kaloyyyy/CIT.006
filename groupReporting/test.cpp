//
// Created by kaloyyyyy on 20/05/2022.
//
#include <iostream>
using namespace std;

bool organicOrNot(){
    char choice;
    cout<<"1. organic       2. inorganic\n";
    cin >> choice;
    if(choice == 1)
        return true;
    else
        return false;
}
int organicCalc(int liquidL){
    int ovenDried, notDried;
    int answer;
    cout<<"input oven dried then not dried values\n";
    cin>>ovenDried;
    cin>>notDried;
    answer = (liquidL-ovenDried)/(liquidL-notDried);
    return answer;
}
int main() {
    //declare variables for the input
    int sieve10, sieve40, sieve200, liquidL, plasticL;
    liquidL = 0;
    bool organic;
    int orgNum;
    cout << "enter Liquid Limit\n";
    cin >> liquidL;
    if (liquidL < 50) {
        orgNum = organicCalc(liquidL);
        if (orgNum <0.75){
            cout<<"organic don't panic\n";
        }else{
            cout<<"di organic\n";
        }
    } else {
        orgNum = organicCalc(liquidL);
        if (orgNum <0.75){
            cout<<"organic don't panic\n";
        }else{
            cout<<"di organic\n";
        }
    }
}

