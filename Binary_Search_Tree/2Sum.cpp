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
void inorder(Node*root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}


int main(){
    Node* root = NULL;
    create(root);
    vector<int>ans;
    inorder(root,ans);
    int target = 5;
    int count=0;
    int s=0,e=ans.size()-1;
    while(s<e){
        int sum=ans[s]+ans[e];
        if(sum == target){
            count++;
            s++;
            e--;
        }
        if(sum <target){
            s++;
        }
        if(sum >target){
            e--;
        }
    }
    cout<<"Count of Sum = target is "<<count;




}
