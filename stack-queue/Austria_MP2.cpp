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
void checkShares();
//declare nodes and variables
node *front = nullptr;
node *rear = nullptr;
int capital, totalShare;

int main() {
    //declare int and char for the inputs.
    int share, price, sell;
    char choice = 'i';
    cout << "Linked list implementation\n\n";
    //switch statement inside a do while loop.
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
                if (capital > 0) {
                    cout << "profit";
                } else if (capital == 0) {

                } else {
                    cout << "loss";
                }
                cout << "total shares: " << totalShare << endl;
                cout << "capital: " << capital << " PHP" << endl << endl << endl;
                break;
            case 'c':
                checkShares();
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 'd');
    return 0;
}

//checking if front and rear is NULL
bool isEmpty() {
    if (front == nullptr && rear == nullptr) {
        return true;
    } else {
        return false;
    }
}

//buy function AKA enqueue function
void buyFunction(int share, int price) {
    node *temp = front;
    node *newNode = new node;
    newNode->share = share;
    newNode->price = price;
    newNode->next = nullptr;
    //newNode becomes the front node if not, then traverses to the last then adds it.
    if (isEmpty()) {
        front = newNode;
    } else {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "shares obtained!\n";
    totalShare = totalShare + newNode->share;
    checkShares();
}

//sellFunction AKA dequeue function with extra steps. sometimes does not dequeue if (shareSell < front->share).
void sellFunction(int sell, int price) {
    int prevPrice;
    int shareSell = sell;
    if (isEmpty()) {
        cout << "portfolio is empty!\n";
    } else if (sell > totalShare) {
        cout << "Not enough shares to sell\n";
        checkShares();
    } else {
        totalShare = totalShare - sell;
        do {
            if (sell >= front->share) {
                //dequeue
                node *temp = front;
                capital = capital + (front->share * (price - front->price));
                sell = sell - front->share;
                front = front->next;
                delete temp;
            } else if (sell < front->share) {
                //does not dequeue but subtracts the shares in the front node.
                capital = capital + (sell * (price - front->price));
                front->share = front->share - sell;
                return;
            }
        } while (sell != 0);
    }
}

void checkShares() {
    if (isEmpty()) {
        cout << "portfolio is empty!\n";
    } else {
        node *temp = front;
        cout << endl << "total shares: " << totalShare << "\nportfolio: \n";
        cout << "count |  price\n";
        while (temp != nullptr) {
            cout << temp->share << "  |  " << temp->price << endl;
            temp = temp->next;
        }
        cout << endl << endl;
    }
}