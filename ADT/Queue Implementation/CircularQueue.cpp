#include<bits/stdc++.h>

using namespace std;

class CircularQueue{
    public:
        int rear,front,size,*arr;
    CircularQueue(int s){
        front = rear= -1;
        size = s;
        arr = new int[s];
    }
    void enqueue(int data){
        if(front==0&&rear==size-1||(rear==(front-1)%(size-1))){
            return;
        }
        else if(front==-1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear==size-1&&front!=0){
            rear=0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
            
        }
    }
};

int main(){

    return 0;
}