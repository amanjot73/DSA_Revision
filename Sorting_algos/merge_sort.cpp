#include<bits/stdc++.h>
using namespace std;

void mergesort(vector<int>&arr,int start,int end){
    int mid = (start+end)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;
    vector<int>first(len1);
    vector<int>second(len2);
    int k =  start;
    for(int i=0;i<len1;i++){
        first[i] = arr[k++];
    }
    for(int i=0;i<len2;i++){
        second[i] = arr[k++];
    }
    k = start;
    int index1 = 0 , index2 =0;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }
    while(index1<len1){
        arr[k++] = first[index1++];
    }
    while(index2<len2){
        arr[k++] = second[index2++];
    }
}



void merge(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    merge(arr,start,mid);
    merge(arr,mid+1,end);
    mergesort(arr,start,end);

}

int main() {
    vector<int>arr = {5,4,3,2,1};
    merge(arr,0,4);
    for(auto &i : arr){
        cout<<i<<" ";
    }
}