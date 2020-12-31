#include<bits/stdc++.h>

using namespace std;

class Queue{
    public:
        int front,rear,size;
        unsigned capacity;
        int* array;
};
        Queue* createQueue(unsigned capacity){
            Queue* q = new Queue();
            q->capacity = capacity;
            q->front = q->size = 0;
            q->rear = capacity-1;
            q->array = new int[(q->capacity * sizeof(int))];
            return q;
        }
        int isFull(Queue* q){
            return (q->size == q->capacity);
        }
        int isEmpty(Queue* q){
            return (q->size==0);
        }
        void Enqueue(Queue* q, int item){
            if(isFull(q)){
                return;
            }
            q->rear = (q->rear+1)%(q->capacity);
            q->array[q->rear] = item;
            q->size = q->size+1;
            cout<<"INSERTED DATA"<<endl;
        }
        int dequeue(Queue* q){
            if(isEmpty(q)){
                cout<<"EMPTY QUEUE"<<endl;
                return INT_MIN;
            }
            int item = q->array[q->front];
            q->front = (q->front+1)%(q->capacity);
            q->size = q->size-1;
            return item;
        }
        int Front(Queue* q){
            if(isEmpty(q)){
                cout<<"QUEUE IS EMPTY"<<endl;
                return -1;
            }
            return q->array[q->front];
        }
        int Rear(Queue* q){
            if(isEmpty(q)){
                cout<<"QUEUE IS FULL"<<endl;
                return -1;
            }
            return q->array[q->rear];
        }



int main(){
    Queue getQ;
    Queue* q  = createQueue(1000);
    Enqueue(q,34);
    Enqueue(q,53);
    Enqueue(q,63);
    cout<<dequeue(q)<<endl;
    cout<<Front(q)<<endl;
    cout<<Rear(q)<<endl;
    return 0;
}