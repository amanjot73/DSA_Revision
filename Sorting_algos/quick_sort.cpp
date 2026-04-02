#include<bits/stdc++.h>
using namespace std;
int part(vector<int>&arr, int start, int end){
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1;i<=end;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int rightindex = start+count;
    swap(arr[start],arr[rightindex]);
    int s=start,e=end;
    while(s<rightindex && e>rightindex){
        while(arr[s]<pivot){
            s++;
        }
        while(arr[e]>pivot){
            e--;
        }
        if(s<rightindex && e>rightindex){
            swap(arr[s++],arr[e--]);
        }
    }
}

void quick(vector<int>&arr , int start , int end){
    if(start>=end){
        return;
    }
    int p = part(arr,start,end);
    quick(arr,start,p-1);
    quick(arr,p+1,end);

}
int main() {
    vector<int>arr = {5,4,3,2,1};
    quick(arr,0,4);
    for(auto &i:arr){
        cout<<i<< " ";
    }
}