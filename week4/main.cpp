#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int stack[10];
    int stSize = 0; //substitute for stack.size
    char choice;
    //loops the switch
    do{
        cout<<"a.push\nb.pop\nc.top\nd.display\ne.exit\n\n";
        cin>>choice;
        switch(choice){
            //limited the stack inputs by 10
            case 'a':
                if(stSize==10){
                   cout<<"stack is already full\n";
                }else{
                    int x;
                    cout<<"enter a value to push into the stack: \n";
                    cin>>x;
                    stack[stSize] = x;//substitute for st.push();
                    cout<<"pushed\n\n";
                    stSize++;
                }
                break;
            case 'b':
                //pops when the stack is not empty
                if(stSize==0){
                    cout<<"stack is still empty\n";
                }else{
                    //pop method
                    stack[stSize] = NULL;
                    stSize--;
                    cout<<"popped\n\n";
                }
                break;
            case'c':
                //display top of stack
                if(stSize==0) {
                    cout << "stack is empty\n";
                }else{
                    cout << "\n stack.top() : " << stack[stSize-1]<<endl;
                }
                break;
            case'd'://display the current size of the stack.
                cout << "\n stack.size() : " <<stSize<<endl;
                break;
        }
    }while(choice!='e');
    return 0;
}