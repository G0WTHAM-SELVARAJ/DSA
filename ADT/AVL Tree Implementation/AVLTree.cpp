#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
        int height;
        int findHeight(Node* n){
            if(n==NULL){
                return 0;
            }
            return n->height;
        }
        Node* newNode(int key){
            Node* n =  new Node();
            n->key = key;
            n->left = NULL;
            n->right = NULL;
            n->height = 1;
            return n;
        }
        Node* rightRotate(Node *y){
            Node *x = y->left;
            Node *T2 = x->right;
            x->right=y;
            y->left=T2;
            y->height = max(findHeight(y->left),findHeight(y->right))+1;
            x->height = max(findHeight(x->left),findHeight(x->right))+1;
            return x;
        }
        Node* leftRotate(Node *x){
            Node *y = x->right;
            Node*T2 = y->left;
            y->left = x;
            x->right = T2;

            x->height = max(findHeight(x->left),findHeight(x->right))+1;
            y->height = max(findHeight(y->left),findHeight(y->right))+1;
            return y;
        }
        int getBalance(Node *N){
            if(N==NULL){
                return 0;
            }
            return findHeight(N->left)-findHeight(N->right);
        }
        Node* insert(Node* root, int key){
            if(root==NULL){
                return(newNode(key));
            }
            if(key<root->key){
                root->left = insert(root->left,key);
            }
            else if(key>root->key){
                root->right = insert(root->right,key);
            }
            else{
                return root;
            }
            root->height = 1 + max(findHeight(root->left),findHeight(root->right));

            int balance = getBalance(root);
            if(balance>1&&key<root->left->key){
                return rightRotate(root);
            }
            if(balance<-1&&key>root->right->key){
                return leftRotate(root);
            }
            if(balance>1&&key>root->left->key){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if(balance<-1&&key<root->right->key){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }
        void preOrder(Node *root){
            if(root){
                cout<<"k: "<<root->key<<"h: "<<root->height;
                preOrder(root->left);
                preOrder(root->right);
            }
        }
};


int main(){
    Node n;
    Node *root = NULL;
    root = n.insert(root,10);
    root = n.insert(root,20);
    root = n.insert(root,30);
    root = n.insert(root, 40);
    root = n.insert(root, 50);
    root = n.insert(root, 25);
    n.preOrder(root);
    return 0;
}
