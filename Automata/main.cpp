#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;




int main() {
    string myText, set1, set2, opSet, elems, str;
    int cases, elType, elTypeSet, opers, opType, item;
    ifstream myReader("mpa1.in");
    myReader >> cases;
    myReader.ignore();
    cout << "number of cases: " << cases << endl;
    int opCount, caseCount = 1;
    while (cases > 0) {
        cout << "\n-------start of case " << caseCount << "------\n";
        myReader >> elType;
        if (elType == 1) {
            set<int> n_set1, n_set2;
        } else if (elType == 2) {
            set<double> n_set1, n_set2;
        } else if (elType == 3) {
            set<char> n_set1, n_set2;
        } else if (elType == 4) {
            set<string> n_set1, n_set2;
        } else if(elType==5) {
            myReader >> elTypeSet;
            if (elTypeSet == 1) {
                set<set<int>> n_set1, n_set2;
            } else if (elTypeSet == 2) {
                set<set<double>> n_set1, n_set2;
            } else if (elTypeSet == 3) {
                set<set<char>> n_set1, n_set2;
            } else{
                set<set<string>> n_set1, n_set2;
            }
        }

        myReader.ignore();
        cout << "element type: " << elType << endl;

        getline(myReader, set1);
        cout << "set 1: " << set1 << endl;
        stringstream set1x(set1);
        string str_temp;
        while(getline(set1x,str_temp, ' ')){
            int i;
            char j;
            double k;
            if (elType == 1) {
                set<int> n_set1;
                i = stoi(str_temp);
                n_set1.insert(i);
            } else if (elType == 2) {
                set<double> n_set1;
            } else if (elType == 3) {
                set<char> n_set1;
            } else if (elType == 4) {
                set<string> n_set1;
            } else if(elType==5) {
                myReader >> elTypeSet;
                if (elTypeSet == 1) {
                    set<set<int>> n_set1;
                } else if (elTypeSet == 2) {
                    set<set<double>> n_set1;
                } else if (elTypeSet == 3) {
                    set<set<char>> n_set1;
                } else{
                    set<set<string>> n_set1;
                }
            }
        }
        getline(myReader, set2);
        cout << "set 2: " << set2 << endl;

        myReader >> opers;
        myReader.ignore();
        cout << "# of operations: " << opers << endl;
        opCount = 1;
        while (opers > 0) {
            getline(myReader, opSet);
            cout << "operation #" << opCount << " : " << endl;
            opCount++;

            stringstream X(opSet);
            while(getline(X,str,' ')){
                cout<<str<<endl;
            }
            opers--;
        }
        cases = cases - 1;
        cout << "--------end of case " << caseCount << "-------\n";
        caseCount++;
    }
    system("pause");
    return 0;
}