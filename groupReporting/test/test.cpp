#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int x = 0;
    cout<<"enter t t t "; 
    cin >>x;
    vector<string> msg {"Hello", "noooooooooooo", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout <<x<<endl;
    cout << endl;
}