#include <iostream>
#include <cmath>
using namespace std;
//declare node, functions and variables.
struct node {
    int share;
    int price;
    node *next;
};
bool isEmpty();
void buyFunction(int share, int price);
void sellFunction(int sell, int price);
void printShare();
//serves as the head of the linked list
node *front = nullptr;
node *rear = nullptr;
int capital, totalShare;

int main() {
    int share, price, sell;
    char choice = 'i';
    cout << "Linked list implementation\n\n";
    do {
        cout << "a.buy shares\nb.sell shares\nc.check shares\nd.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                cout << "amount to buy:\n";
                cin >> share;
                cout << "enter share price\n";
                cin >> price;
                buyFunction(share, price);
                break;
            case 'b':
                cout << "amount to sell: \n";
                cin >> sell;
                cout << "enter share price\n";
                cin >> price;
                sellFunction(sell, price);
                cout << "total shares: " << totalShare << endl;
                cout << "capital: " << capital << " PHP" << endl << endl << endl;
                break;
            case 'c':
                printShare();
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

void buyFunction(int share, int price) {//adds a node to the queue
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
    cout << "shares obtained!\n";
    totalShare = totalShare + newNode->share;
    printShare();
}

void sellFunction(int sell, int price) {//removes the first node of the queue or linked list
    int prevPrice;
    int shareSell = sell;
    if (isEmpty()) {
        cout << "portfolio is empty!\n";
    } else if (sell > totalShare) {
        cout << "Not enough shares to sell\n";
        printShare();
    } else {
        totalShare = totalShare - shareSell;
        // Move the head pointer to the next node
        do {
            if (shareSell >= front->share) {
                node *temp = front;
                //insert calculations
                prevPrice = temp->price;
                capital = capital + (front->share * (price - prevPrice));
                shareSell = shareSell - front->share;
                front = front->next;
                delete temp;
            } else if (shareSell < front->share) {
                capital = capital + (front->share * (price - front->price));
                front->share = front->share - shareSell;
                return;
            }
        } while (sell != 0);
    }
}

void printShare() {
    if (isEmpty()) {
        cout << "portfolio is empty!\n";
    } else {
        node *temp = front;
        cout << endl << "total shares: " << totalShare << "\nportfolio: \n";
        cout << "share count  |  share price\n";
        while (temp != nullptr) {
            cout << temp->share << "  |  " << temp->price << endl;
            temp = temp->next;
        }
        cout << endl << endl;
    }
}