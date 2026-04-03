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
int len(Node*root){
    if(root == NULL){
        return 0;
    }
    return len(root->left)+ len(root->right)+1;
}
bool check_balanced(Node*root){
    if(root == NULL){
        return  true;
    }
    bool l = check_balanced(root->left);
    bool r = check_balanced(root->right);
    bool diff = abs(len(root->left)-len(root->right)) <=1;
    if(l&&r&&diff){
        return true;
    }
    else{
        return false;
    }

}
Node* final_balanced(int s,int e,vector<int>&ans){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* temp = new Node(ans[mid]);
    temp->left = final_balanced(s,mid-1,ans);
    temp->right = final_balanced(mid+1,e,ans);
    return temp;
}


Node* balance(Node*root){
    vector<int>ans;
    inorder(root,ans);
    root = final_balanced(0,ans.size()-1,ans);
    return root;
}




int main(){
    Node* root ;
    create(root);
    cout<<(check_balanced(root)?"Yes\n":"No\n");
    root = balance(root);
    cout<<(check_balanced(root)?"Yes\n":"No\n");

}