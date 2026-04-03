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
void create(Node* &root){
    int k;
    cin>>k;
    if(k==-1){
        return;
    }
    root = new Node(k);
    create(root->left);
    create(root->right);
}
void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool check(Node*root,int min,int max){
    if(root == NULL){
        return true;
    }
    if(root->data >=min && root->data <=max){
        bool l  = check(root->left,min,root->data);
        bool r  = check(root->right,root->data,max);

        return (l&&r);

        
    }
    else{
        return false;
    }
}


int main() {
    Node* root = NULL;
    create(root);
    inorder(root);
    cout<<(check(root,INT_MIN,INT_MAX)?"\nYES":"\nNO");

}