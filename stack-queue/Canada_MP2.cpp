#include <iostream>
using namespace std;

struct node {
    int share;
    int price;
    node *next;
};
bool isEmpty();
node *front = nullptr;
node *rear = nullptr;
int gainLoss, totalShare;

//check if front and rear is NULL
bool isEmpty() {
    if (front == nullptr && rear == nullptr) {
        return true;
    } else {
        return false;
    }
}

//traverse through the nodes and prints the share and price at the time bought.
void printShare() {
    if (isEmpty()) {
        cout << "portfolio is empty\n";
    } else {
        node *temp = front;
        cout << endl << "total shares: " << totalShare << endl;
        cout << "shares --- price" << endl;
        while (temp != nullptr) {
            cout << temp->share << " --- " << temp->price << " php" << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}

//adds a node/buy to the shares
void buyShareFunc(int share, int price) {
    node *temp = front;
    node *newNode = new node;
    newNode->share = share;
    newNode->price = price;
    newNode->next = nullptr;
    if (isEmpty()) {
        //sets the new and first node as the head/front
        front = newNode;
    } else {
        while (temp->next != nullptr) {
            //traverse the linked list
            temp = temp->next;
        }
        //add new node to the list
        temp->next = newNode;
    }
    cout << "shares bought!\n";
    totalShare = totalShare + newNode->share;
    printShare();
}

//may or may not sellShare depends on the shares to be sold.
//sell function based on sellShare
void sellShareFunc(int sell, int price) {
    int prevPrice;
    int shareSell = sell;
    if (isEmpty()) {
        cout << "queue is empty\n";
    } else if (sell > totalShare) {
        cout << "You don't have enough shares to sell\n";
        printShare();
    } else {
        totalShare = totalShare - shareSell;
        // Move the head pointer to the next node
        do {
            if (shareSell >= front->share) {
                node *temp = front;
                prevPrice = temp->price;
                gainLoss = gainLoss + (front->share * (price - prevPrice));
                shareSell = shareSell - front->share;
                front = front->next;
                delete temp;
            } else if (shareSell < front->share) {
                gainLoss = gainLoss + (shareSell * (price - front->price));
                front->share = front->share - shareSell;
                shareSell = 0;
            }
        } while (shareSell != 0);
    }
}


int main() {
    int buyShares, sharePrice, sellShares;
    char choice = 'x';
    do {
        cout << "a.buy  b.sell   c.check   d.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a'://buyShare
                cout << "enter number of shares:\n";
                cin >> buyShares;
                cout << "enter share value\n";
                cin >> sharePrice;
                buyShareFunc(buyShares, sharePrice);
                break;
            case 'b':
                cout << "shares to sell: \n";
                cin >> sellShares;
                cout << "enter the share value\n";
                cin >> sharePrice;
                sellShareFunc(sellShares, sharePrice);
                printShare();
                cout << "profit: " << gainLoss << endl;
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
