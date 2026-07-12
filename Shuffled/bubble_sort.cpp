#include<bits/stdc++.h>
using namespace std;
void sort(int arr[] , int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main() {
    int arr[5] = {5,4,3,2,1};
    sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

}