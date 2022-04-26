#include <iostream>
#include <cmath>
using namespace std;

struct node {
    char num;
    node *next;
};
node *head;
node *top;

void convert(int input, int base);
char reVal(int num);
void push(char input);
void pop();
void reverse_order(node *p);

int main() {
    char exit = 'n';
    int num;
    int base;
    do {
        cout << "\nenter a base-10 integer\n";
        cin >> num;
        cout << "choose a base\na. binary\nb. octal\nc. hexadecimal\nd. exit" << endl;
        cin >> exit;
        switch (exit) {
            case 'a':
                base = 2;
                break;
            case 'b':
                base = 8;
                break;
            case 'c':
                base = 16;
                break;
            default:
                cout << "enter a valid choice\n";
                break;
        }
        convert(num, base);
    } while (exit != 'd');
    return 0;
}

// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num) {
    if (num >= 0 && num <= 9) {
        return (char) (num + '0');
    } else {
        return (char) (num - 10 + 'A');
    }
}

// Function to convert a given decimal number
// to a base 'base'
void convert(int input, int base) {
    int tempNum;
    // Convert input number is given
    // base by repeatedly dividing it
    // by base and taking remainder
    while (input > 0) {
        tempNum = input % base;
        char val = reVal(tempNum);
        push(val);
        input = input / base;
    }
    reverse_order(head);
}

//displays each node from top to head by using recursion
void reverse_order(node *p) {
    if (p == nullptr) {
        return;
    }
    reverse_order(p->next);
    cout << top->num;
    pop();
}

//print then pop the result
void pop() {
    if (head->next == nullptr) {//delete head and top node.
        head = nullptr;
        top = nullptr;
    } else {
        node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        top = temp;//second to the last becomes the top node
        node *lastNode = temp->next;//next or last node becomes "lastNode"
        temp->next = nullptr;//next becomes null
        free(lastNode);//free lastNode
    }
}

void push(char input) {
    node *temp = head;
    node *newNode = new node;
    newNode->num = input;
    newNode->next = nullptr;
    //sets the new and first node as the head
    top = newNode;
    if (head == nullptr) {
        head = newNode;
    } else {
        //traverse the linked list
        //add new node to the list
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}