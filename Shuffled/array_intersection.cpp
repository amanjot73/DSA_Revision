#include<bits/stdc++.h>
using namespace std;
void intersection(int arr[],int arr2[],int n , int m){
    int i=0,j=0;
    vector<int> result;
    while(i<n && j<m){
        if(arr[i] == arr2[j]){
            if(result.empty() || result.back() !=arr[i]){
                result.push_back(arr[i]);
            }
            i++;
            j++;
           
        }
        else if(arr[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for(int i: result){
        cout<<i<<" ";
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
    int size2;
    cout<<"Enter Size\n";
    cin>>size2;
    cout<<"Enter array elements\n";
    int arr2[100] = {0};
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    intersection(arr,arr2,size,size2);


}