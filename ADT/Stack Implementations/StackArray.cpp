#include<bits/stdc++.h>

using namespace std;



class Stack{
        int top;
    public:
        int a[1000];
        Stack(){
            top = -1;
        }
        bool push(int x){
            if(top>=999){
                cout<<"STACK OVERFLOW"<<endl;
                return false;
            }
            else{
                a[++top] = x;
                cout<<"PUSHED INTO STACK"<<endl;
                return true;
            }
        }
        int pop(){
            if(top<0){
                cout<<"STACK UNDERFLOW"<<endl;
                return -1;

            }
            else{
                int x = a[top--];
                return x;
            }
            return -1;
        }
        int peek(){
            if(top<0){
                cout<<"STACK EMPTY"<<endl;
                return -1;
            }
            else{
                int x = a[top];
                return x;
            }
            return -1;
        }
        bool isEmpty(){
            return (top<0);
        }
};

int main(){
    Stack s;
    s.push(4);
    s.push(34);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}
