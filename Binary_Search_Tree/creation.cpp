#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node*left;
        Node*right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};
Node* result(Node*root, int k){
    if(root == NULL){
        root = new Node(k);
        return root;
    }
    if(root->data <k){
        root->right = result(root->right,k);
    }
    else{
        root->left = result(root->left,k);
    }
    return root;
}
void create(Node*&root){
    int k ; 
    cin>>k;
    while(k!=-1){
        root = result(root,k);
        cin>>k;
    }
}


void inorder(Node* root){
    if(root ==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    Node*root = NULL;
    create(root);
    inorder(root);

}