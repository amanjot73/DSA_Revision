#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main() {
    vector<int>arr = {5,4,3,2,1};
    bubble(arr);
    for(auto &i :arr){
        cout<<i<<" ";
    }

}