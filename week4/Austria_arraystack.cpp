#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int st[5];
    int stSize = 0; //substitute for st.size
    char choice;
    do{//loops the switch
        cout<<"a.push\nb.pop\nc.top\nd.display\ne.exit\n\n";
        cin>>choice;
        switch(choice){//for the selection menu
            case 'a'://limited the stack inputs by 5
                if(stSize==5){
                   cout<<"stack is already full\n";
                }else{
                    int x;
                    cout<<"enter a value to push into the stack: \n";
                    cin>>x;
                    st[stSize] = x;//substitute for st.push();
                    cout<<"pushed\n\n";
                    stSize++;
                }
                break;
            case 'b':
                if(stSize==0){//pops when the stack is not empty
                    cout<<"stack is still empty\n";
                }else{
                    st[stSize] = NULL; //these two lines is substitute for st.pop();
                    stSize--;
                    cout<<"popped\n\n";
                }
                break;
            case'c'://displays the top value if there exists
                if(stSize==0) {
                    cout << "stack is empty\n";
                }else{
                    cout << "\n st.top() : " << st[stSize-1]<<endl;
                }
                break;
            case'd'://display the current size of the stack.
                cout << "\n st.size() : " <<stSize<<endl;
                break;
        }
    }while(choice!='e');
    return 0;
}