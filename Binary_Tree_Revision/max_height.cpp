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

void height(Node* root, int &n1 , int &n2){
    if(root == NULL){
        return;
    }
    n2++;
    if(n2>n1){
        n1 = n2;
    }
    height(root->left,n1,n2);
    height(root->right,n1,n2);
    n2--;
}


int main(){
    Node* root = NULL;
    root = create(root);
    int n1=0,n2=0;
    height(root,n1,n2);
    cout<<n1;

}