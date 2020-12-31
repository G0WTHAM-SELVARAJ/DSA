#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
};

class DoublyLinkedList{
    public:
        Node* insertFront(Node*head, int data){
            Node* n  = new Node();
            n->data = data;
            n->next = head; 
            n->prev = NULL;
            if(head!=NULL){
                head->prev = n ;
            }
            head = n;
            return head;
        }
        void insertAfter(Node*prevNode, int data){
            if(prevNode==NULL){
                return;
            }
            Node* n = new Node();
            n->data = data;
            n->next = prevNode->next;
            prevNode->next  = n;
            n->prev = prevNode;
            if(n->next!=NULL){
                n->next->prev = n;
            }
        }
        void printList(Node*head){
            if(head==NULL){
                return;
            }
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        void printReverseList(Node*last){
            if(last==NULL){
                return;
            }
            Node* temp = last;
            while(last!=NULL){
                cout<<temp->data<<" ";
                temp=temp->prev;
            }
            cout<<endl;
        }
        Node* insertBack(Node* head, int data){
            Node* n = new Node();
            Node* last = head;
            n->data = data;
            n->next = NULL;
            if(head==NULL){
                n->prev = NULL;
                head  = n;
            }
            while(last->next!=NULL){
                last = last->next;
            }
            last->next = n;
            n->prev = last;
            return last->next;
        }
        void insertBefore(Node* nextNode, int data){
            Node* n = new Node();
            n->data = data;
            if(nextNode==NULL){
                return;
            }
            n->next = nextNode;
            n->prev = nextNode->prev;
            nextNode->prev = n;
            if(n->prev!=NULL){
                n->prev->next = n;
            }

        }
        void deleteNode(Node* head, Node* delNode){
            if(head==NULL||delNode==NULL){
                return;
            }
            if(head==delNode){
                head = delNode->next;
            }
            if(delNode->prev!=NULL){
                delNode->prev->next = delNode->next;
            }
            if(delNode->next!=NULL){
                delNode->next->prev = delNode->prev;
            }
            free(delNode);
            return;
        }
};

int main(){
    int n;
    DoublyLinkedList dll;
    Node* head = NULL;  
    Node* last = NULL;
    head = dll.insertFront(head,5);
    dll.insertAfter(head,239);
    last = dll.insertBack(head,4);
    dll.insertBefore(last,35);
    dll.printList(head);
    dll.deleteNode(head,last->prev->prev);
    dll.printReverseList(last);
}