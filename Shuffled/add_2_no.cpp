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
Node* at_tail(Node* &n ,Node* &n2, int val){
    if(n == NULL){
        Node* nww = new Node(val);
        n = nww;
        n2 = n;
        n = nww;
    }
    else{
        Node* temp = new Node(val);
        n2->next = temp;
        n2 = temp;
    }
    return n;
}
void print(Node* n){
    Node* temp = n;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
Node* rev (Node* n){
    Node* prev = NULL;
    Node* curr  = n;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next =prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node* add(Node* &n,Node* &m){
    n = rev(n);
    m = rev(m);
    Node* head = NULL;
    Node* tail = NULL;
    int carry = 0;
    while(n!=NULL && m!=NULL){
        int val1 = n->data;
        int val2 = m->data;
        int sum = val1+val2+carry;
        int r = sum%10;
        carry = sum/10;
        Node*neww = new Node(r);
        if(head == NULL){
            head = neww;
            tail = head;

        }
        else{

            tail->next = neww;
            tail = tail->next;


        }
        n=n->next;
        m = m->next;
        
    }
    while(n!=NULL){
        int s =0;
        if(carry!=0){
            s = n->data + carry;
        }
        else{
            s = n->data;
        }
        Node*neww = new Node(s);
        tail->next = neww;
        tail = tail->next;
        n = n->next;
    }
    while(m!=NULL){
        int s =0;
        if(carry!=0){
            s = m->data + carry;
        }
        else{
            s = m->data;
        }
        Node*neww = new Node(s);
        tail->next = neww;
        tail = tail->next;
        m = m->next;
    }
    head = rev(head);
    return head;
}
int main() {
    Node* n = NULL;
    Node*n1 = NULL;
    at_tail(n,n1,4);
    at_tail(n,n1,6);
    at_tail(n,n1,0);
    Node* m = NULL;
    Node*m1 = NULL;
    at_tail(m,m1,3);
    at_tail(m,m1,9);
    print(n);
    cout<<endl;
    print(m);
    cout<<endl;
    Node* f = add(n,m);
    print(f);
}