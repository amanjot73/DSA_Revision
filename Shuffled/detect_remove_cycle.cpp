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
    
        Node*neww = new Node(val);
        n->next = neww;
        n = neww;

    
}
Node* floydcycledetection(Node* n){//loop detection
    Node*slow = n;
    Node* fast = n;
    while(fast->next!=NULL && fast!=NULL && slow!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
    
}
Node* getstartofcycle(Node* n){//Start node of cycle
    Node* temp = floydcycledetection(n);
    Node* start = n;
    while(start !=NULL && temp!=NULL){
        start = start->next;
        temp  = temp->next;
        if(start == temp){
            return start;
        }
    }
}
void remove(Node* &n){//remove cycle
    Node* temp  = getstartofcycle(n);
    Node*temp2 = temp;
    while(temp2->next !=temp){
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    n = temp;


}
void print(Node* n){
    Node* temp = n;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main() {
    Node*n = NULL;
    Node*n1 = NULL;
    cout<<"enter nodes of ll"<<endl;
    for(int i=0;i<5;i++){
        int a ;
        cin>>a;
        if(n==NULL){
            n = new Node(a);
            n1 = n;
        }
        else{
            at_tail(n1,a);

        }
    }
    n1->next = n->next;//jst for making my ll circular


    if(floydcycledetection(n1)){
        cout<<"Cycle"<<endl;
    }
    else{
        cout<<"Non"<<endl;
    }
    Node*k = getstartofcycle(n1);
    cout<<"Cycle starts at "<<k->data<<endl;
    remove(n1);
    if(floydcycledetection(n1)){
        cout<<"Cycle"<<endl;
    }
    else{
        cout<<"Non"<<endl;
    }

}