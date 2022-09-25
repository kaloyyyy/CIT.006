#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string myText, set1, set2;
    int cases, elType, opers, opType, set, item;
    ifstream myReader("mpa1.in");
    myReader>>cases;
    cout<<"number of cases: "<<cases<<endl;
    myReader>>elType;
    cout<<"element type: "<<elType<<endl;
    myReader.ignore();
    getline(myReader, set1);
    cout<<"set 1: "<<set1<<endl;
    getline(myReader,set2);
    cout<<"set 2: "<<set2<<endl;
    myReader>>opType;
    cout<<"operation: "<<opType<<endl;


    while(getline (myReader, myText)){
        cout<<myText<<endl;
    }

    return 0;
}