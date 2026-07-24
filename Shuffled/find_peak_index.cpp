#include<bits/stdc++.h>
using namespace std;
int peak(int arr[] , int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[mid] <arr[mid+1] ){
            start = mid+1;
        }
        else{
            end = mid; // main thing to remember
        }
    }
    return start;
}
int main() {
int size;
    cout<<"size-> ";
    cin>>size;
    cout<<endl;
    int arr[size] = {0};
    cout<<"Enter elements \n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<peak(arr,size);

}