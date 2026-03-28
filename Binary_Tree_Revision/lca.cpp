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
Node*lca (Node*root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* l = lca(root->left,n1,n2);
    Node* r = lca(root->right,n1,n2);
    if(l == NULL && r!=NULL){
        return r;
    }
    if(l != NULL && r==NULL){
        return l;
    }
    if(l != NULL && r!=NULL){
        return root;
    }
    else{
        return NULL;
    }

}
int main(){
    Node*root = NULL;
    root = create(root);
    Node* ans = lca(root,8,6);
    cout<<ans->data;


}
