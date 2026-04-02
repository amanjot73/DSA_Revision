#include<bits/stdc++.h>
using namespace std;
void selection(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
int main() {
    vector<int>arr = {5,4,3,2,1};
    selection(arr);
    for(auto &i :arr){
        cout<<i<<" ";
    }

}