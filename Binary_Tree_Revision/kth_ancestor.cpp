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
bool check2(Node* root , vector<int>&ans,int target){
    if(root == NULL){
        return false;
    }
    ans.push_back(root->data);
    if(root -> data == target){
        return true;
    }
    bool l = check2(root->left,ans,target);
    bool r = check2(root->right,ans,target);
    if(l||r){
        return true;
    }
    else{
        ans.pop_back();
        return false;
    }

}

void check(Node*root ,int k){
    vector<int>ans;
    int target = 4;
    
    if(check2(root,ans,target)){
        reverse(ans.begin(),ans.end());
        int a=0;
        if(k>ans.size()){
            cout<<"Enter valid value of k";
            return;
        }
        for(int i=0;i<=k;i++){
            a = ans[i];
        }
        cout<<a;

    }
    else{
        cout<<"Not found";
    }
}
int main(){
    Node* root = NULL;
    root = create(root);
    check(root,10);

}