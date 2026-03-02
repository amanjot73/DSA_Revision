#include<bits/stdc++.h>
using namespace std;
void bottom(stack<int>&s,int t){
    if(s.empty()){
        s.push(t);
        return;
    }
    int t2= s.top();
    s.pop();
    bottom(s,t);
    s.push(t2);
}
void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int t= s.top();
    s.pop();
    reverse(s);
    bottom(s,t); // we will use the bottom insertion function.

    
}
int main() {
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}