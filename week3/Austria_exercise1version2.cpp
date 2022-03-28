#include <iostream>
#include <cstdlib>//for system("CLS");
using namespace std;

struct node{
    char name[50];
    int age;
    node *next;
};

node *start_ptr=nullptr;
void addNode1();
void displayNode();

int main(){
    char choice = 'a';
    do{//do while for the menu. exits only when user inputs c.
        cout<<"enter your choice\na.add\nb.view\nc.exit"<<endl;
        cin>>choice;
        system("CLS");//clear the screen
        switch(choice){//within the do while loop there is a switch for adding and displaying nodes.
            case 'a':
                addNode1();
                break;
            case 'b':
                displayNode();
                break;
            default:
                break;
        }
    }while(choice != 'c');
}

void addNode1(){//nothing much is changed except I followed 1. c. in the document.
    node *addnode = new node;
    cout << "Enter your friend's name: ";
    cin.ignore();
    cin.getline(addnode->name,50);
    cout << "Enter your friend's age: ";
    cin >> addnode->age;
    addnode->next = nullptr;
    addnode->next=start_ptr;
    start_ptr=addnode;
}

void displayNode(){
    node *temp=start_ptr;
    cout <<"Your friend's list:" << endl;
    while(temp!=nullptr){
        cout << temp->name << "\t" << temp->age << "\t" << endl;
        temp=temp->next;
    }
    cout<<endl<<endl;//added endl.
}