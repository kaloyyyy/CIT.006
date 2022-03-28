#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int share;
    int price;
    node *next;
};
bool isEmpty();
void buyShare(int share, int price);
void sellShare(int sell, int price);
void displayFront();
void printShare();
node *front = nullptr;//serves as the head of the linked list
node *rear = nullptr;
int gainLoss, totalShare;

int main() {
    int share, price, sell;
    char choice = 'i';
    cout << "Linked list implementation\n\n";
    do {
        cout << "a.buy shares\nb.sellShare\nc.Front\nd.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a'://buyShare
                cout << "enter number of shares:\n";
                cin >> share;
                cout << "enter share value\n";
                cin >> price;
                buyShare(share, price);
                break;
            case 'b':
                cout << "shares to sell: \n";
                cin >> sell;
                cout << "enter the share value\n";
                cin >> price;
                sellShare(sell, price);
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

void buyShare(int share, int price) {//adds a node to the queue
    node *temp = front;
    node *newNode = new node;
    newNode->share = share;
    newNode->price = price;
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
    totalShare += totalShare;
    printShare();
}

void sellShare(int sell, int price) {//removes the first node of the queue or linked list
    if (isEmpty()) {
        cout << "queue is empty\n";
    } else if (totalShare < sell) {
        cout << "You don't have enough shares to sell\n current: " << totalShare;
    } else {
        // Move the head pointer to the next node
        if (sell >= front->share) {
            node *temp = front;
            //insert calculations
            totalShare -= sell;
            gainLoss += front->share * (price - front->price);
            front = front->next;
            delete temp;
            sell -= front->share;
            sellShare(sell, price);
        } else {
            totalShare -= sell;
            gainLoss += front->share * (price - front->price);
        }
    }
    printShare();
}

void printShare() {
    if (isEmpty()) {
        cout << "portfolio is empty\n";
    } else {
        node *temp = front;
        cout << endl << "portfolio: ";
        while (temp != nullptr) {
            cout << temp->share << " : " << temp->price << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}