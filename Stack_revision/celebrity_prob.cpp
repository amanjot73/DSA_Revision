#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> arr = {{0,1,1,0},{1,0,1,1},{1,1,0,1},{0,0,0,0}};
    stack<int>s;
    for(int i=0;i<arr.size();i++){
        s.push(i);
    }
    while(s.size()>1){
        int one  = s.top();
        s.pop();
        int two  = s.top();
        s.pop();
        if(arr[one][two]){
            s.push(two);
        }
        else{
            s.push(one);
        }
    }
    cout<<s.top();

}
