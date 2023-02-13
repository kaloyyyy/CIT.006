#include <iostream>
using namespace std;

struct node{
	char letter;
	int number;
	node *next;
	};

node *start_ptr= nullptr;

void addNode1();
void displayNode();

int main(){
	addNode1();
	addNode1();
	addNode1();
	addNode1();
	addNode1();
	displayNode();
    return 0;
}

void addNode1()
{
	node *addnode = new node;
	cout << "Enter letter: ";
	cin>>addnode->letter;
	cout << "Enter number ";
	cin >> addnode->number;
	addnode->next = NULL;
	cin.ignore();
	
	if(start_ptr==NULL){
		start_ptr=addnode;}
	else
	{
		addnode->next=start_ptr;
		start_ptr=addnode;
	}
	
}

void displayNode()
{
	node *temp=start_ptr;
	cout << endl << "Your list" << endl;
	while(temp!=NULL)
	{
		cout << temp->letter << temp->number << endl;
		temp=temp->next;
	}
}

