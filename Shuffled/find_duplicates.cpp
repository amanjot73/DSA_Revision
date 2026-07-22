#include<bits/stdc++.h>
using namespace std;
void duplicate(int arr[] ,int size){
    vector<int> result;
    for(int i=0;i<size;i++){
        int index = abs(arr[i]) -1;
        if(arr[index]<0){
            result.push_back(abs(arr[i]));
        }
        else{
            arr[index] = -(arr[index]);
        }

    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    
}
int main() {
    int size;
    cout<<"Enter Size\n";
    cin>>size;
    cout<<"Enter array elements\n";
    int arr[100] = {0};
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    duplicate(arr,size);
    

}