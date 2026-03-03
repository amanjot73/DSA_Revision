#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    stack<int>s;
    s.push(-1);
    vector<int> result;
    for(int i=arr.size()-1;i>=0;i--){
        while(s.top()>arr[i]){
            s.pop();
        }
        result.push_back(s.top());
        s.push(arr[i]);

    }
    reverse(result.begin() , result.end());
    for(auto &i:result){
        cout<<i<<" ";
    }
}