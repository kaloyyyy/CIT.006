#include <iostream>
using namespace std;

#define SIZE 13
int arr[SIZE];
int front = -1;
int rear = -1;

bool isEmpty();
void enqueue(int x);
void dequeue();
void printQueue();

int main() {
    int input;
    char choice = 'i';
    cout << "Circular Array\n";
    do {
        cout << "a.enqueue\nb.dequeue\nc.Front\nd.Rear\ne.exit";
        cin >> choice;
        switch (choice) {
            case 'a'://enqueue
                cout << "enter input:  ";
                cin >> input;
                enqueue(input);
                break;
            case 'b':
                dequeue();
                break;
            case 'c'://displays front
                if (isEmpty()) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "element at front is:" << arr[front];
                }
                break;
            case 'd'://displays rear
                if (isEmpty()) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "element at rear is:" << arr[rear];
                }
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
    } while (choice != 'e');

}

//Function to check if queue is empty or not
bool isempty() {
    if (front == -1 && rear == -1) {
        return true;
    } else {
        return false;
    }
}

void enqueue(int x) {
    //queue is full
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is full \n";
    } else {
        //first element inserted
        if (front == -1) {
            front = 0;
        }
        //insert element at rear
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }
    printQueue();
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
    } else
        //only one element
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printQueue();
}

void printQueue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        int i;
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            i = front;
            while (i < SIZE) {
                cout << arr[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear) {
                cout << arr[i] << " ";
                i++;
            }
        }
    }
}