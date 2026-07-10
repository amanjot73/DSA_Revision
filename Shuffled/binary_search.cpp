#include<bits/stdc++.h>
using namespace std;
void binary(int arr[],int element, int size){
    int start=0;
    int end = size;
    int mid = (start)+(end-start)/2;//optimization
    while(start<=end){
        if(arr[mid] == element){
            cout<<"element found at index-> "<<mid;
            break;
        }
        if(arr[mid]>element){
            end = mid-1;
        }
        if(arr[mid]<element){
            start = mid +1;
        }
        mid = (start+end)/2;

    }
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
    cout<<"\n enter element to search ->";
    int element;
    cin>>element;
    binary(arr,element,size);

}