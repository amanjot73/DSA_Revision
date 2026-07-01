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
void inorder(Node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
bool IsSum(Node* root,int target){
    vector<int>ans;
    inorder(root,ans);
    int i=0,j= ans.size()-1;
    while(i<j){
        int sum = ans[i]+ans[j];
        if(sum == target){
            return true;
        }
        if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;

}
int main(){
    Node* root = NULL;
    root = create();
    if(IsSum(root,20)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}