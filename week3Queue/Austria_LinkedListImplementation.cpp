#include <iostream>
using namespace std;

struct node {
    int num;
    node *next;
};
bool isEmpty();
void enqueue(int x);
void dequeue();
void displayFront();void printQueue();
//initializing both front and rear
node *front = nullptr;//serves as the head of the linked list
node *rear = nullptr;

int main() {
    int input;
    char choice = 'i';
    cout << "Linked list implementation\n\n";
    do {
        cout << "a.enqueue\nb.dequeue\nc.Front\nd.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a'://enqueue
                cout << "enter input:\n";
                cin >> input;
                enqueue(input);
                break;
            case 'b':
                if (isEmpty()) {
                    cout << "queue is empty\n";
                } else {
                    dequeue();
                }
                break;
            case 'c':
                displayFront();
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 'd');
    return 0;
}

bool isEmpty() {
    if (front == nullptr && rear == nullptr) {   //checking if front and rear is NULL
        return true;
    } else {
        return false;
    }
}

void enqueue(int x) {//adds a node to the queue
    node *temp = front;
    node *newNode = new node;
    newNode->num = x;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;//sets the new and first node as the head/front
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;//traverse the linked list
        }
        temp->next = newNode;//add new node to the list
    }
    cout << "value queued\n";
    printQueue();
}

void dequeue() {//removes the first node of the queue or linked list
    if (isEmpty()) {
        cout << "queue is empty\n";
    } else {
        // Move the head pointer to the next node
        node *temp = front;
        front = front->next;
        delete temp;
    }
    printQueue();
}

void displayFront() {//prints the front of the queue
    if (isEmpty()) {
        cout << "queue is empty\n";
    } else {
        cout << "front: " << front->num << endl;
    }
}
void printQueue(){
    if(isEmpty()){
        cout<<"queue is empty\n";
    }else{
        node *temp=front;
        cout << endl << "queue: ";
        while(temp!=nullptr){
            cout << temp->num<<"   ";
            temp=temp->next;
        }
        cout<<endl;
    }
}