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
vector<int> bottom(Node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<Node*,int> > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        // }
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));

        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));

        }
    }
    for(auto i: topNode){
        
        ans.push_back(i.second);
        
    }
    return ans;
   
}
int main() {
    Node* root = NULL;
    root = create(root);
    vector<int>ans = bottom(root);
    for(auto i: ans){
        cout<<i<<" ";
    }

}