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
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp  = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left !=NULL){
                q.push(temp->left);
            }
            if(temp->right !=NULL){
                q.push(temp->right);
            }
        }

    }
}
void inorder(Node* root , int &count){
    //lnr
    if(root == NULL){
        return;
    }
    inorder(root->left,count);
    if(root->left== NULL && root->right == NULL){
        count++;
    }
    
    inorder(root->right,count);

}
int count(Node* root){
    int c=0;
    inorder(root,c);
    return c;

}
int main() {
    Node* root = NULL;
    create(root);
    
    cout<<count(root);


}