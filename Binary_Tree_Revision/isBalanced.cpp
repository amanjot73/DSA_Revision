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
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
}
bool balanced(Node* root){
    if(root == NULL){
        return true;
    }
    bool l = balanced(root->left);
    bool r = balanced(root->right);
    bool diff = abs(height(root->left) - height(root->right))<=1;
    if(l && r && diff){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    Node* root = NULL;
    root = create(root);
    cout<<(balanced(root)?"Yes its a balanced tree":"No");
}