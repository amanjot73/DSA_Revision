#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void at_tail(Node* &n,int val){
    Node*temp = new Node(val);
    n->next = temp;
    n = temp;
}
void print(Node* n){
    Node* temp = n;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
void del(Node* &n , int val){
    Node* prev = NULL;
    Node* curr = n;
    if(n->data == val){
        Node* todel = n;
        n = n->next;
        delete todel;
        return;
    }
    while(curr!=NULL && curr->data !=val){
        prev = curr;
        curr = curr->next;
    }
    if(curr!=NULL){
        prev->next = curr->next;
        delete curr;
    }

}
Node* remove(Node* &n){
    Node* temp = n;
    while(temp!=NULL){
        int val = temp->data;
        Node*nex = temp->next;
        if(val %2==0){
            del(n,val);
        }
        temp = nex;
    }
    return n;
}



int main(){
    Node*n = new Node(2);
    Node*n1 = n;
    at_tail(n1,7);
    at_tail(n1,6);
    at_tail(n1,4);
    at_tail(n1,3);
    print(n);
    cout<<endl;
    Node*m = remove(n);
    print(m);

}