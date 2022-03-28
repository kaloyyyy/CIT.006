#include <iostream>
using namespace std;

struct node{
    char name[50];
    int age;
    node *next;
};

node *start_ptr=nullptr;

void addNode1();
void displayNode();

int main()
{
    addNode1();
    displayNode();
    cout << endl << endl;


    addNode1();
    displayNode();

}

void addNode1()
{
    node *addnode = new node;
    cout << "Enter your friend's name: ";
    cin.getline(addnode->name,50);
    cout << "Enter your friend's age: ";
    cin >> addnode->age;
    addnode->next = nullptr;
    cin.ignore();

    if(start_ptr==nullptr)
        start_ptr=addnode;
    else
    {
        addnode->next=start_ptr;
        start_ptr=addnode;
    }

}

void displayNode()
{
    node *temp=start_ptr;
    cout << endl << "Your friend's list:" << endl;
    while(temp!=nullptr)
    {
        cout << temp->name << "\t" << temp->age << "\t" << endl;
        temp=temp->next;
    }
}


