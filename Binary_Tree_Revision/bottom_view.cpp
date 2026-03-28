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
void bottom(Node*root){
    if(root == NULL){
        return;
    }
    bottom(root->left);
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    bottom(root->right);

}
int main(){
    Node* root = NULL;
    root = create(root);
    bottom(root);
}