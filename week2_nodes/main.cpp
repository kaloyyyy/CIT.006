#include <iostream>
#include<string>//for get line for string;
#include <cstdlib>
using namespace std;
class node{
public:
	string name;
	int age{};
    double height{};
	node* next_ptr{};
};
void addNode(node*& head, node*& last, const string& name, int age, double height);
bool isEmpty(node* head);
void viewNode(node* current);
void delNode(node*& head);
void searchNode(node* current);
void ageSort(node* current);
void nameSort(node* current);
void validateInt();
int main() {
    node* head = nullptr;
    node* last = nullptr;
    string name;
    int age;
    double height;
    char choice = 'a';

    do{
        cout<<"enter your choice\na.add\nb.view\nc.delete\nd.search\ne.exit"<<endl;
        cin>>choice;
        switch(choice){
            case 'a':
                system("CLS");
                cout << "enter your friend's name: \n";
                cin.ignore();
                getline(cin, name);

                cout << "enter " << name << "'s " << "age: \n";
                cin >> age;
                if(cin.fail()){
                    while(cin.fail()){
                        validateInt();
                        cin>>age;
                    }
                }
                cout <<"enter "<<name<<"'s "<<"height: \n";
                cin >>height;
                if(cin.fail()){
                    while(cin.fail()){
                        validateInt();
                        cin>>height;
                    }
                }

                system("CLS");
                cout<<name<<" is now added!\n\n";
                addNode(head, last, name, age, height);
                break;
            case 'b':
                viewNode(head);
                break;
            case 'c':
                delNode(head);
                break;
            case 'd':
                searchNode(head);
                break;
            default:
                break;
        }
    }while(choice != 'e');
    return 0;
}

void addNode(node*& head, node*& last, const string& name, int age, double height){//adds a new friend
    if (isEmpty(head)) {
        node* temp = new node;
        temp->name = name;
        temp->age = age;
        temp->height = height;
        temp->next_ptr = nullptr;
        head = temp;
        last = temp;
    } else {
        node *temp = new node;

        temp->name = name;
        temp->age = age;
        temp->height = height;

        temp->next_ptr = nullptr;
        last->next_ptr = temp;
        last = temp;
    }
}
bool isEmpty(node* head){//checks if the linked list is empty
    if (head == nullptr){
        return true;
    }else{
        return false;
    }
}

void viewNode(node* current)//view friend menu
{
    system("CLS");
    if (isEmpty(current)){
        cout << "record is empty\n";
    }else{
        system("CLS");
        cout << "---your Friend list---\n\n";
        while (current != nullptr)
        {
            cout << "name: " << current->name << endl;
            cout << "age: " << current->age << endl;
            cout << "height: " << current->height << endl<<endl<<endl;
            current = current->next_ptr;
        }
    }
}

void delNode(node*& head){
    char delChoice;
    node *now;
    cout<<"a. delete first node\nb. delete last node"<<endl;
    cin>>delChoice;
    if(isEmpty(head)){
        system("CLS");
        cout<<"record is empty"<<endl;
    }else{
        switch(delChoice){
            case 'a':
                now = head;
                head = now->next_ptr;
                delete now;
                break;
            case 'b':
                if(head != nullptr) {
                    if (head->next_ptr == nullptr) {
                        now = head;
                        head = now->next_ptr;
                        delete now;
                        delete head;
                    }else {
                        // Find the second last node
                        node *second_last = head;
                        while (second_last->next_ptr->next_ptr != nullptr)
                            second_last = second_last->next_ptr;
                        // Delete last node
                        delete (second_last->next_ptr);
                        // Change next_ptr of second last
                        second_last->next_ptr = nullptr;
                    }
                }
                break;
            default:
                break;
        }
    }
}
void ageSort(node* current)//age filter function.
{
    int ageFilter;
    bool ageMatch = false;

    cout << "enter age filter\n";
    cin >> ageFilter;
    if(cin.fail()){
        while(cin.fail()){
            validateInt();
            cin>>ageFilter;
        }
    }
    system("CLS");
    while (current != nullptr){
        if (current->age == ageFilter){
            if(!ageMatch)	cout << "records with age equal to" << ageFilter << endl << endl;
            cout << "name: " << current->name << endl;
            cout << "age: " << current->age << endl;
            cout << "height: " << current->height << endl<<endl<<endl;
            current = current->next_ptr;
            ageMatch = true;
        }else{
            current = current->next_ptr;
            if (current == nullptr){
                if (!ageMatch){
                    cout << "no records with age: " << ageFilter << endl;
                }
            }
        }
    }
}
void nameSort(node*current){
    bool nameMatch = false;
    string viewName;
    cout << "enter full name to search\n";
    cin.ignore();
    getline(cin, viewName);
    cout << "searching for " << viewName << "..." << endl << endl;
    while (current != nullptr)
    {
        if (current->name.find(viewName)!=string::npos)
        {
            cout << "name: " << current->name << endl;
            cout << "age: " << current->age << endl;
            cout << "height: " << current->height << endl<<endl<<endl;
            current = current->next_ptr;
            nameMatch = true;
        }
        else
        {
            current = current->next_ptr;
            if (current == nullptr)
            {
                if (!nameMatch)
                {
                    system("CLS");
                    cout << "no records with name: " << viewName << endl;
                }
            }
        }
    }
}
void searchNode(node* current){
    char filterChoice = 'a';
    if (isEmpty(current)){
        cout << "record is empty\n";
    }else {
        cout << "a. age filter\nb. name search\n";
        cin >> filterChoice;
    }
    switch (filterChoice) {
        case 'a':
            ageSort(current);
            break;
        case 'b':
            nameSort(current);
        default:
            break;
    }
}
void validateInt(){
    cout<<"enter a valid integer:"<<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}