#include<bits/stdc++.h>
using namespace std;
void bottom(stack<int>&s){
    if(s.empty()){
        s.push(1984);
        return;
    }
    int t= s.top();
    s.pop();
    bottom(s);
    s.push(t);
}
int main() {
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // it will print in a order => 5,4,3,2,1.
    // so we will insert the element i.e 1984 at bottom i.e our new
    // stack will become 5,4,3,2,1,1984.
    // We will do this by recursion. Let's go.
    bottom(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}