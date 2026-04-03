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
int minval(Node*root){

    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

Node* del(Node*root,int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == k){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left !=NULL && root->right ==NULL){
            Node*temp = root->left;
            delete root;
            return temp;
        }
        if(root->left ==NULL && root->right !=NULL){
            Node*temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right !=NULL){
            int m = minval(root->right);
            root->data = m;
            root->right = del(root->right,m);
            return root;

        }

    }
    else if(root->data <k){
        root->right = del(root->right,k);
        return root;
    }
    else{
        root->left = del(root->left,k);
        return root;
    }
}
void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node*root = NULL;
    create(root);
    inorder(root);
    root = del(root,4);
    cout<<endl;
    inorder(root);
}