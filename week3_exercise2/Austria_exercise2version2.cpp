#include <iostream>
#include <cstdlib>//for system("CLS");
using namespace std;

struct node{
    char name[50];
    int age;
    node *next;
};

node *start_ptr=nullptr;

void addNode2();
void displayNode();

int main(){
    char choice = 'a';
    do{//do while for the menu. exits only when user inputs c.
        cout<<"enter your choice\na.add\nb.view\nc.exit"<<endl;
        cin>>choice;
        system("CLS");//clear the screen
        switch(choice){//within the do while loop there is a switch for adding and displaying nodes.
            case 'a':
                addNode2();
                break;
            case 'b':
                displayNode();
                break;
            default:
                break;
        }
    }while(choice != 'c');
}

void addNode2(){
    node *hopper=start_ptr;
    node *addnode = new node;
    cout << "Enter your friend's name: ";
    cin.getline(addnode->name,50);
    cout << "Enter your friend's age: ";
    cin >> addnode->age;
    addnode->next = NULL;
    cin.ignore();
    if(start_ptr==NULL)
        start_ptr=addnode;
    else{
        while(hopper->next!= nullptr){
            hopper=hopper->next;
        }
        hopper->next=addnode;
    }
}

void displayNode(){
    node *temp=start_ptr;
    cout << endl << "Your friend's list:" << endl;
    while(temp!=nullptr){
        cout << temp->name << "\t" << temp->age << "\t" << endl;
        temp=temp->next;
    }
}