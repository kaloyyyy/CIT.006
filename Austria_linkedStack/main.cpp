#include <iostream>
using namespace std;
struct node{
    int num;
    node *next;
};
node *head;
node *top;
void push();
void pop();
void display();
int main() {
    int stSize=0;
    char choice;
    do{//loops the switch
        cout<<"a.push\nb.pop\nc.top and size\nd.display\ne.exit\n\n";
        cin>>choice;
        switch(choice){//for the selection menu
            case 'a':
                    push();//substitute for stack.push();
                    stSize++;
                break;
            case 'b':
                if(stSize==0){//pops when the stack is not empty
                    cout<<"stack is still empty\n";
                }else{
                    pop(); //these two lines is substitute for st.pop();
                    stSize--;
                    cout<<"popped\n\n";
                }
                break;
            case'c'://displays the top value and stack size if there exists
                if(stSize==0) {
                    cout << "stack is empty\n";
                }else{
                    cout << "top: "<<top->num<<endl;
                    cout <<"stack size: "<<stSize<<endl;
                }
                break;
            case'd'://display the the stack.
                if(stSize==0) {
                    cout << "stack is empty\n";
                }else{
                    display();
                }
                break;
        }
    }while(choice!='e');
}
void push() {
    node *temp = head;
    node *newNode = new node;
    cout << "Enter the value: \n";
    cin >> newNode->num;
    newNode->next = nullptr;
    if (head == nullptr){
        head = newNode;//sets the new and first node as the head
    }else{
        while(temp->next != nullptr){
            temp=temp->next;//traverse the linked list
        }
        temp->next=newNode;//add new node to the list

    }
    top = newNode;
    cout<<"value pushed\n";
}
void pop(){
    if(head->next== nullptr){//delete head and top node.
        head = nullptr;
        top = nullptr;
    }else{
        node *temp=head;
        while(temp->next->next != nullptr)
            temp = temp->next;
        top = temp;//second to the last becomes the top node
        node* lastNode = temp->next;//next or last node becomes "lastNode"
        temp->next = nullptr;//next becomes null
        free(lastNode);//free lastNode
    }
}
void display(){//displays each node from head to top
    node *temp=head;
    cout << endl << "stack: " << endl;
    while(temp!=nullptr){
        cout << temp->num<<endl;
        temp=temp->next;
    }
}