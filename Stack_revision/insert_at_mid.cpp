#include<bits/stdc++.h>
using namespace std;
void rec(stack<int>&s ,int mid,int count){
    if(count==mid){ // this is my base condition. 
        s.push(1984);// If we reach the mid element , we will push the element and return.
        return;
    }
    int t = s.top();
    s.pop();
    rec(s,mid,count+1);
    s.push(t); // most imp step , remember to push_back the poped elements.....

}
void middle(stack<int>&s){
    int count = 0;
    int mid = s.size()/2;
    rec(s,mid,count);

}
int main() {
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // it will print in a order => 5,4,3,2,1.
    // so we will insert the element i.e 1984 at mid i.e our new
    // stack will become 5,4,1984,3,2,1.
    // We will do this by recursion. Let's go.
    middle(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}