#include<bits/stdc++.h>
using namespace std;
void insertion(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int temp = arr[i];
        int j = i-1;
        for(j;j<arr.size()-1;j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }

        }
        arr[j+1] = temp;
        
    }
}
int main() {
    vector<int>arr = {5,4,3,2,1};
    insertion(arr);
    for(auto &i :arr){
        cout<<i<<" ";
    }

}