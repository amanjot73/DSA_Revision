#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};
Node* create(Node* &root){
    cout<<"Enter Data : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter element to be inserted in the left of "<<data<<endl;
    root->left = create(root->left);
    cout<<"Enter element to be inserted in the right of "<<data<<endl;
    root->right = create(root->right);
    return root;

}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
    
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";

}
int main(){
    Node* root  = NULL;
    root = create(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
}