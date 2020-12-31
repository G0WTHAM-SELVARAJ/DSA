
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
class LinkedList{
    public:
        void printList(Node* n){
            while(n!=NULL){
                cout<<n->data<<" ";
                n = n->next;
            }
        }
        Node* insertFront(int data,Node* head){
            Node* n= new Node();
            n->data = data;
            n-> next = head;
            head = n;
            return head;
        }
        void insertAfter(Node* prev, int data){
            Node* n = new Node();
            n->data = data;
            n->next = prev->next;
            prev->next = n;
        }
        void insertBack(int data,Node* head){
            Node* n = new Node();
            n->data = data;
            n->next = NULL;
            Node* last =head;
            if(head == NULL){
                head = n;
                return;
            }
            while(last->next!=NULL){
                last = last->next;
            }
            last->next = n;
            return;
        }
        Node* deleteNode(int data, Node* head){
            Node* temp = head;
            Node* prev = NULL;
            if(temp!=NULL&&temp->data==data){
               // cout<<head->data<<endl;
                head = temp->next;
               // cout<<head->data<<endl;
                free(temp);
                return head;
            }
            while(temp!=NULL&&temp->data!=data){
                prev = temp;
                temp = temp->next;
            }
            if(temp==NULL){
                return NULL;
            }
            prev->next = temp->next;
            free(temp);
            return head;
        }
        Node* deleteAt(Node* head, int position){
            Node* temp = head;
            Node* prev = NULL;
            int i=0;
            if(position==0){
                head = temp->next;
                free(temp);
                return head;
            }
            while(temp!=NULL&&i!=position){
                prev = temp;        
                temp = temp->next;
                i++;
            }
            if(temp == NULL){
                return NULL;
            }
            prev->next = temp->next;
            free(temp);
            return head;

        }
        Node* deleteList(Node* head){
            Node* current = head;
            Node* next;
            while(current!=NULL){
                next = current->next;
                free(current);
                current = next;
            }
            return head = NULL;
        }
        int sizeofList(Node* head){
            int count=0;
            Node* temp = head;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        }
        int sizeofListRec(Node* head){
            if(head==NULL){
                return 0;
            }
            return 1+sizeofListRec(head->next);
        }
        Node* getNthNode(Node* head, int index){
            Node* temp = head;
            int i;
            while(temp!=NULL){
                if(i==index){
                    return temp;
                }
                temp = temp->next;
                i++;
            }
            return temp;
        }
};


int main(){
    LinkedList li;
    Node* head = NULL;
    Node* temp = NULL;
    int index,n;
    head = li.insertFront(5,head);
    head = li.insertFront(6,head);
    li.insertBack(10,head);
    li.insertAfter(head->next,25);
    //li.printList(head);
    //head = li.deleteNode(6,head);
    //head = li.deleteAt(head,0);
    //head = li.deleteList(head);
    n = li.sizeofListRec(head);
    cout<<"LIST SIZE "<<n<<endl;
    li.printList(head);
    cout<<endl;
    cin>>index;
    temp = li.getNthNode(head,index);
    cout<<temp->data<<endl;
    return 0;
}