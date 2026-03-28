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
void check(Node*root , vector<int>ans,int &count,int sum,int target){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    for(int i = ans.size()-1;i>=0;i--){
        sum+=ans[i];
        if(sum==target && i!=ans.size()-1){
            count++;
        }
    }
    sum=0;

    check(root->left,ans,count,sum,target);
    check(root->right,ans,count,sum,target);
    ans.pop_back();
}


int main(){
    Node*root = NULL;
    root  = create(root);
    int target = 3, count = 0 , sum = 0;
    vector<int>ans;
    check(root,ans,count,sum,target);
    cout<<count;



}