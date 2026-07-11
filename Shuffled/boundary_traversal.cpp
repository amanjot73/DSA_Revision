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
Node* create(Node* root){
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
void count(Node* temp , vector<int>&result){
    if(temp == NULL){
        return;
    }
    count(temp->left,result);
    if(temp->left == NULL && temp->right == NULL){
        int d = temp->data;
        result.push_back(d);
    }
    count(temp->right,result);
}
void traversalLeft(Node*temp , vector<int>&result){
    if(temp == NULL || temp->left == NULL && temp->right == NULL){
        return;
    }
    result.push_back(temp->data);
    if(temp->left){
        traversalLeft(temp->left,result);
    }
    else{
        traversalLeft(temp->right,result);
        
    }
}
void traversalRight(Node*temp , vector<int>&result){
    if(temp == NULL || (temp->left == NULL && temp->right == NULL)){
        return;
    }
    if(temp->right){
        traversalRight(temp->right,result);
    }
    else{
        traversalRight(temp->left,result);
        
    }
    result.push_back(temp->data);
}
vector<int>boundary (Node* root){
    vector<int>result;
    if(root == NULL){
        return result;
    }
    result.push_back(root->data);
    traversalLeft(root->left,result);
    count(root,result);
    traversalRight(root->right,result);
    return result;

}
int main() {
    Node* root = NULL;
    root = create(root);
    vector<int>ans = boundary(root);
    for(auto &i:ans){
        cout<<i<<" ";
    }

}