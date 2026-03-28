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
void solve(Node*root,vector<int>&ans,int level){
    if(root == NULL){
        return;
    }
    if(ans.size() == level){
        ans.push_back(root->data);
    }
    if(root->left){
        solve(root->left,ans,level+1);
    }
    if(root->right){
        solve(root->right,ans,level+1);
    }
    

}
vector<int> check(Node*root){
    vector<int>ans;
    int level=0;
    solve(root,ans,level);
    return ans;
    
}
int main(){
    Node* root = NULL;
    root = create(root);
    vector<int>ans = check(root);
    for(auto &i:ans){
        cout<<i<<" ";
    }
}

