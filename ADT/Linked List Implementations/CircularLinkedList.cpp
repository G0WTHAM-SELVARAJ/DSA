#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
class CircularLinkedList{
    public:
        Node* addToEmpty(Node* last , int data){
            if(last!=NULL){
                return last;
            }
            Node* temp = new Node();
            temp->data = data;
            last = temp;
            temp->next = last;
            return last;
        }
        Node* addBegin(Node* last, int data){
            if(last==NULL){
                return addToEmpty(last,data);
            }
            Node* n = new Node();
            n->data = data;
            n->next = last->next;
            last->next = n;
            return last;
        }
        Node* addEnd(Node* last, int data){
            if(last==NULL){
                return addToEmpty(last,data);
            }
            Node* n = new Node();
            n->data = data;
            n->next = last->next;
            last->next = n;
            last = n;
            return last;
        }
        Node* addAfter(Node* last, int data, int item){
            if(last==NULL){
                return NULL;
            }
            Node* n,*p;
            p = last->next;
            do{
                if(p->data==item){
                    n = new Node();
                    n->data = data;
                    n->next = p->next;
                    p->next = n;
                    if(p==last){
                        last = n;
                    }
                    return last;
                }
                p=p->next;
            }
            while(p!=last->next);
            return last;
        }
        void traverse(Node* last){
            Node* p = NULL;
            if(last==NULL){
                return;
            }
            p = last->next;
            do{
                cout<<p->data<<endl;
                p = p->next;
            }
            while(p!=last->next);
        }

};


int main(){
    Node* locate = NULL;
    CircularLinkedList cll;
    locate = cll.addBegin(locate, 4);
    locate = cll.addAfter(locate,34,4);
    locate = cll.addEnd(locate,238);
    cll.traverse(locate);
    return 0;
}