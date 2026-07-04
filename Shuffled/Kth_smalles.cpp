// // #include<bits/stdc++.h>
// // using namespace std;
// // class Node{
// //     public:
// //         int data;
// //         Node* left;
// //         Node* right;
// //     Node(int data){
// //         this->data = data;
// //         this->left = NULL;
// //         this->right = NULL;
// //     }

// // };
// // Node* create(Node* root){
// //     cout<<"Enter Data : "<<endl;
// //     int data;
// //     cin>>data;
// //     root = new Node(data);
// //     if(data == -1){
// //         return NULL;
// //     }
// //     cout<<"Enter element to be inserted in the left of "<<data<<endl;
// //     root->left = create(root->left);
// //     cout<<"Enter element to be inserted in the right of "<<data<<endl;
// //     root->right = create(root->right);
// //     return root;

// // }
// // vector<int> zigzag(Node* root){
// //     vector<int>result;
// //     if(root==NULL){
// //         return result;
// //     }
// //     bool leftToRight = true;
// //     queue<Node*>q;
// //     q.push(root);

// //     while(!q.empty()){
// //         int size = q.size();
// //         vector<int>ans(size);
// //         for(int i=0;i<size;i++){
// //             Node* firstNode = q.front();
// //             q.pop();
// //             int index = leftToRight?i:size-i-1;
// //             ans[index] = firstNode->data;
// //             if(firstNode->left){
// //                 q.push(firstNode->left);
// //             } 
// //             if(firstNode->right){
// //                 q.push(firstNode->right);
// //             }
// //         }
// //         for(auto i:ans){
// //             result.push_back(i);
// //         }
// //         leftToRight = !(leftToRight);
// //     }
// // }
// // void left(Node* root,vector<int>&ans,int level){
// //     if(root == NULL){
// //         return;
// //     }
// //     if(level == ans.size()){
// //         ans.push_back(root->data);
// //     }
// //     left(root->right,ans,level+1);
// //     left(root->left,ans,level+1);

// // }
// // vector<int> vertical(Node* root){
// //     map<int,map<int,vector<int> > > nodes;
// //     queue<pair<Node*,pair<int,int>>> q;
// //     vector<int>ans;
// //     if(root==NULL){
// //         return ans;
// //     }
// //     q.push(make_pair(root,make_pair(0,0)));
// //     while(!q.empty()){
// //         pair<Node*,pair<int,int>> temp = q.front();
// //         q.pop();
// //         Node* frontNode = temp.first;
// //         int hd = temp.second.first;
// //         int level = temp.second.second;
// //         if(nodes.find(hd) == nodes.end()){

// //             nodes[hd][level].push_back(frontNode->data);
// //         }
// //         if(frontNode->left){
// //             q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
// //         }
// //         if(frontNode->right){
// //             q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));

// //         }
// //     }
// //     for(auto i: nodes){
// //         for(auto j:i.second){
// //             for(auto k:j.second){
// //                 ans.push_back(k);
// //             }
// //         }
// //     }
// // }
// // int main() {
// //     Node* root = NULL;
// //     root = create(root);
// //     // int level = 0;
// //     vector<int>ans = vertical(root);
// //     for(auto i:ans){
// //         cout<<i<<" ";
// //     }


// // }
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//         int data;
//         Node* left;
//         Node* right;
//     Node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }

// };
// Node* create(Node* root){
//     cout<<"Enter Data : "<<endl;
//     int data;
//     cin>>data;
//     root = new Node(data);
//     if(data == -1){
//         return NULL;
//     }
//     cout<<"Enter element to be inserted in the left of "<<data<<endl;
//     root->left = create(root->left);
//     cout<<"Enter element to be inserted in the right of "<<data<<endl;
//     root->right = create(root->right);
//     return root;

// }
// void solve(Node* root,int len,int &maxlen,int sum,int &maxsum){
//     if(root == NULL){
//         if(len>maxlen){
//             maxlen = len;
//             maxsum = sum;
//         }
//         else if(len == maxlen){
//             maxsum = max(maxsum,sum);
//         }
//         return;
//     }
//     sum = sum+root->data;
//     solve(root->left,len+1,maxlen,sum,maxsum);
//     solve(root->right,len+1,maxlen,sum,maxsum);
// }
// int max(Node* root){
//     int len =0;
//     int maxlen = 0;
//     int sum = 0;
//     int maxsum = INT_MIN;
//     solve(root,len,maxlen,sum,maxsum);
//     return maxsum;

// }
// int main() {
//     Node* root = NULL;
//     root = create(root);
//     cout<<max(root);

// }
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
void solve(Node* root , int &i,int k,int &r){
    if(root == NULL){
        return;
    }
    solve(root->left,i,k,r);
    if(i==k){
        r = root->data;
    }
    i++;
    solve(root->right,i,k,r);
}
int smallest(Node* &root,int k){
    int r = -1;
    int i=1;
    solve(root,i,k,r);
    return r;

}
int main() {
    Node* root = NULL;
    cout<<"enter values for bst : "<<endl;
    takeInput(root);
    cout<<endl<<smallest(root,2);
    

}