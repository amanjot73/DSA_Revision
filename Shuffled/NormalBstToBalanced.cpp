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
Node* create(){
    int data;
    cin >> data;

    if(data == -1){   // stop recursion here
        return NULL;
    }

    Node* root = new Node(data);
    root->left = create();
    root->right = create();
    return root;
}
void inorder(Node* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void inorder2(Node* root){
    if(root == NULL){
        return;
    }
    inorder2(root->left);
    cout<<root->data<<" ";
    inorder2(root->right);
}
Node* final(int start,int end,vector<int>&ans){
    
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node* temp = new Node(ans[mid]);
    temp->left = final(start,mid-1,ans);
    temp->right = final(mid+1,end,ans);
    return temp;

}
Node* balanced(Node* root){
    vector<int>ans;
    inorder(root,ans);
    return final(0,ans.size()-1,ans);
    // return temp;

}
int main(){
    Node* root = NULL;
    root = create();
    Node* b = balanced(root);
    inorder2(b);

}