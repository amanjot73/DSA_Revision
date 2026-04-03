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
void lca(Node*root,int n1,int n2){
    while(root!=NULL){
        if(root->data >n1 && root->data >n2){
            root = root->left;
        }
        if(root->data <n1 && root->data <n2){
            root = root->right;
        }
        else{
            cout<<root->data;
            return;
        }

    }
}

int main(){
    Node*root ;
    create(root);
    lca(root,2,5);

}