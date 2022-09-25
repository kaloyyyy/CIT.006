#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string myText, set1, set2;
    int cases, elType, opers, opType, set, item, caseCount;
    ifstream myReader("mpa1.in");
    myReader>>cases;
    cout<<"number of cases: "<<cases<<endl;
    caseCount = 1;
    while(cases>0){
        cout<<"\n-------start of case "<<caseCount<<"------\n";
        myReader>>elType;
        cout<<"element type: "<<elType<<endl;
        myReader.ignore();
        getline(myReader, set1);
        cout<<"set 1: "<<set1<<endl;
        getline(myReader,set2);
        cout<<"set 2: "<<set2<<endl;
        myReader>>opType;
        cout<<"operation: "<<opType<<endl;
        cases = cases - 1;
        cout<<"--------end of case "<<caseCount<<"-------\n";
        caseCount++;
    }
    system("pause");
    return 0;
}