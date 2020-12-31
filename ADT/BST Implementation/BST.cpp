#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;
};

class BST{
    public:
        Node* search(Node* root, int key){
            if(root==NULL||root->key==key){
                cout<<"search node: "<<root->key<<endl;
                return root;
            }
            if(root->key<key){
                return search(root->right,key);
            }
            if(root->key>key){
                return search(root->left,key);
            }
            return root;
        }
        Node* insert(Node* root, int key){
            if(!root){
                Node* n = new Node();
                n->key = key;
                n->left = NULL;
                n->right = NULL;
                return n;
            }
            if(key>root->key){
                root->right = insert(root->right,key);
            }
            else{
                root->left = insert(root->left, key);
            }
            return root;
        }
        void inorder(Node* root){
            if(root!=NULL){
                inorder(root->left);
                cout<<root->key<<" ";
                inorder(root->right);
            }
        }
        Node* minValue(Node* root){
            Node* min = root;
            while(min&&min->left!=NULL){
                min = min->left;
            }
            cout<<"THE MINIMUM VALUE OF THE BST IS "<<min->key<<endl;
            return min;
        }
        void maxValue(Node* root){
            Node* max = root;
            while(max&&max->left!=NULL){
                max = max->left;
            }
            cout<<"THE MAXIMUM VALUE OF THE BST IS "<<max->key<<endl;
        }
        Node* del(Node* root, int key){
            if(root == NULL){
                return root;
            }
            if(key>root->key){
                root->right = del(root->right,key);
            }
            else if(key< root->key){
                root->left = del(root->left, key);
            }
            else{
                if(root->left==NULL){
                    Node* temp = root->right;
                    free(root);
                    return temp;
                }
                else if(root->right==NULL){
                    Node* temp = root->left;
                    free(root);
                    return temp;
                }
                Node* temp = minValue(root->right);
                root->key = temp->key;
                root->right = del(root->right,temp->key);   
            }
            return root;
        }
};

int main(){
    Node* root = NULL;
    BST b; 
    root = b.insert(root, 34);
    root = b.insert(root, 323);
    root = b.insert(root, 12);
    root = b.insert(root, 23);
    root= b.insert(root,512);
    b.search(root,34);
    cout<<root->key<<endl;
    b.inorder(root);
    root = b.del(root, 23);
    b.inorder(root);
    return 0;
}