#include <iostream>
using namespace std;

int enqueue(int x);
int dequeue();
int printQueue();
//initializes queue size and array
int queueSize = 0;
int arr[13];

int main() {
    int input;
    char choice = 'i';
    cout<<"Linear array implementation\n\n";
    do {
        cout << "a.enqueue\nb.dequeue\nc.Front\nd.exit\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                if (queueSize == 13) {
                    cout << "queue is full";
                } else {
                    cout << "enter input:  ";
                    cin >> input;
                    enqueue(input);
                }
                break;
            case 'b':
                if (queueSize == 0) {
                    cout << "queue is empty\n";
                } else {
                    dequeue();
                }
                break;
            case 'c':
                cout << arr[0];
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 'd');

}

int enqueue(int x) {
    int i = 0;
    if (queueSize == 0) {
        arr[i] = x;//input is added to the last
    } else {
        for (i = 0; i < queueSize; i++) {
        }
        arr[i] = x;//input is added to the last
    }
    queueSize++;//new value is added to the queue thus the size grows
    printQueue();
    return 0;
}

int dequeue() {
    int i;
    for (i = 0; i < queueSize; i++) {
        arr[i] = arr[i + 1];//index 0 is assigned equal to index 0+1 and so on... until the queueSize is reached.
    }
    queueSize--;
    printQueue();
    return 0;
}

int printQueue() {
    int i;
    cout << "current queue: ";
    for (i = 0; i < queueSize; i++) {
        cout << arr[i] << "    ";
    }
    cout << endl;
    return 0;
}