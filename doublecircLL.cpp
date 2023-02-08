#include <iostream>

using namespace std;

#include <cstring>

struct node {
    int id{};
    string name;
    char gender{};
    node *next{};
    node *prev{};
};

bool isEmpty(node *head) {//checks if the linked list is empty
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}

void addNode(node *&head, node *&last, const string &name, int id, char gender) {//adds a new friend
    if (isEmpty(head)) {
        node *temp = new node;
        temp->name = name;
        temp->id = id;
        temp->gender = gender;
        temp->next = nullptr;
        temp->prev = nullptr;
        head = temp;
        last = temp;
    } else {
        node *temp = new node;

        temp->name = name;
        temp->id = id;
        temp->gender = gender;
        temp->prev = last;
        temp->next = head;
        last->next = temp;
        last = temp;
        head->prev = last;
    }
}

void viewAllNodes(node *current, node *head)//view friend menu
{
    char input;
    if (isEmpty(current)) {
        cout << "record is empty\n";
    } else {
        cout << "---your list---\n\n";
        do {
            cout << "name: " << current->name << endl;
            cout << "id: " << current->id << endl;
            cout << "gender: " << current->gender << endl << endl << endl;
            current = current->next;
        } while (current != head);
    }
}

void viewGender(node *current, node *head, char gender)//view friend menu
{
    char input;
    if (isEmpty(current)) {
        cout << "record is empty\n";
    } else {
        cout << "---your list---\n\n";
        do {
            if(gender == current->gender){
                cout << "name: " << current->name << endl;
                cout << "id: " << current->id << endl;
                cout << "gender: " << current->gender << endl << endl << endl;
            }
            current = current->next;
        } while (current != head);
    }
}

void viewNode(node *current, node *head)//view friend menu
{
    char input;
    if (isEmpty(current)) {
        cout << "record is empty\n";
    } else {
        cout << "---your list---\n\n";
        cout << "name: " << current->name << endl;
        cout << "id: " << current->id << endl;
        cout << "gender: " << current->gender << endl << endl << endl;
        do {
            cout << "\na.next  b.prev  c.del  X.exit\n";
            cin >> input;
            node *prev = current->prev;
            node *next = current->next;
            node *now = current;
            switch (input) {
                case 'a':
                    cout << "name: " << current->name << endl;
                    cout << "id: " << current->id << endl;
                    cout << "gender: " << current->gender << endl << endl << endl;
                    prev = current->prev;
                    next = current->next;
                    now = current;
                    current = current->next;
                    break;
                case 'b':
                    cout << "name: " << current->name << endl;
                    cout << "id: " << current->id << endl;
                    cout << "gender: " << current->gender << endl << endl << endl;
                    prev = current->prev;
                    next = current->next;
                    now = current;
                    current = current->prev;
                    break;
                case 'c':
                    if(now == head){
                        head = now->next;
                    }
                    delete now;
                    next->prev = prev;
                    prev->next = next;
                    current = head;
                    break;
                default:
                    break;
            }
        } while (input != 'X');
    }
}

int main() {
    int studCount = 0;
    char choice;
    cout << "enter number of students";
    cin >> studCount;
    node *head = nullptr;
    node *last = nullptr;
    for (int i = 0; i < studCount; i++) {
        int id;
        string name;
        char gender;
        cout << "enter id\n";
        cin >> id;
        cout << "enter name\n";
        cin >> name;
        cout << "enter gender\n";
        cin >> gender;
        addNode(head, last, name, id, gender);
    }

    do {
        cout << "a. Traverse entire LL   m/f. traverse depend on gender   c.delete/traverse  X.exit";
        cin >> choice;
        switch (choice) {
            case 'a':
                viewAllNodes(head, head);
                break;
            case 'm':
                viewGender(head,head,'m');
                break;
            case 'f':
                viewGender(head,head,'f');
                break;
            case 'c':
                viewNode(head,head);
                break;
        }
    } while (choice != 'X');
    return 0;
}
