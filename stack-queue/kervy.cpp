#include<iostream>
using namespace std;


struct node {
    char value;
    node *next;
};
node *top = NULL;
node *ptr = NULL;
node *p = NULL;
int x;


bool isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}


void push(char val) {
    ptr = new node;
    ptr->value = val;
    ptr->next = NULL;
    if (top == NULL) {
        top = ptr;
    } else {
        ptr->next = top;
        top = ptr;
    }
}


int pop() {
    if (isEmpty()) {
        cout << "No number entered: " << endl;
    } else {
        p = top;
        top = top->next;
        x = p->value;
        cout << x;
        delete (p);
        return (x);

    }
}

void convert(int base) {
    cout << "Enter number: ";
    cin >> value;
    cout << "Quotient" << "\t Remainder" << endl;
    while (value > 0) {
        a = value % base;
        value = value / base;
        cout << value << "/"<<base<<" \t" << "\t" << a << endl;
        push(a);
    }
    p = top;
    cout << "Octal no: \n";
    while (true) {
        if (top != NULL) {
            pop();
        } else {
            break;
        }
    }
}

int main() {
    int value, a;
    char hno = 'A';
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char option;
    int base;
    do {

        cout
                << "\nA. BINARY(0, 1) \nB. OCTAL(0, 1, 2, 3, 4, 5, 6, 7) \nC. HEXADECIMAL(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F) \nD. EXIT"
                << endl;
        cin >> option;

        switch (option) {
            case 'A':
                base = 2;


                break;

            case 'B':
               base = 8;
                break;

            case 'C':
              base = 16;
                break;
        }
        convert(base);

    } while (option != 'D');
    cout << "Thankyou" << endl;
    return 0;
}//
// Created by kaloyyyyy on 22/04/2022.
//

