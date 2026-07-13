#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {4,5,1,2,3};
    int count = 0;
    for(int i= 1;i<arr.size();i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }    
    if(arr[arr.size()-1]>arr[0]){
        count++;

    }
    if(count<=1){//why <=1 for the case of -> {1,1,1} leetcode
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}