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
Node*insertToBst(Node* root,int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(root->data >d){
        root->left = insertToBst(root->left,d);
    }
    else{
        root->right= insertToBst(root->right,d);

    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertToBst(root,data);
        cin>>data;
    }

}
Node* minVal(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
Node* del(Node* &root, int element){
    if(root == NULL){
        return root;
    }
    if(root->data == element){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root ->left == NULL && root->right !=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left !=NULL && root->right ==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left !=NULL && root->right !=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = del(root->right,mini);
            return root;
        }
    }
    else if(root->data >element){
        root->left = del(root->left,element);
        return root;
    }
    else{
        root->right = del(root->right,element);
        return root;
    }
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root = NULL;
    takeInput(root);
    cout<<endl;
    root = del(root,27);
    inorder(root);
    
}