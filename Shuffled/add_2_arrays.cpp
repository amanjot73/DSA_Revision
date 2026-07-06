#include<bits/stdc++.h>
using namespace std;
void add(vector<int>&arr1,vector<int>&arr2,vector<int>&arr3){
    int carry=0;
    int end1 = arr1.size()-1;
    int end2 = arr2.size()-1;
    int end3 = arr3.size()-1;
    while(end1>=0 && end2>=0){
        int sum = arr1[end1--] + arr2[end2--]+carry;
        int remainder = sum%10;
        int quotient = sum/10;
        carry = quotient;
        arr3[end3--] = remainder;
    }
    while(end1>=0){
        arr3[end3--] = arr1[end1--]+carry;
        carry = 0;   
    }
    while(end2>=0){
        arr3[end3--] = arr2[end2--]+carry;
        carry = 0;   
    }
}
int main() {
    int size1,size2;
    cout<<"size1 -> ";
    cin>>size1;
    cout<<"\n size2 -> ";
    cin>>size2;
    cout<<"Enter arr1 -> ";
    vector<int>arr1(size1);
    vector<int> arr2(size2);
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    cout<<"\nEnter arr2 -> ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    int size3 = max(size1,size2);
    vector<int>arr3(size3); 
    add(arr1,arr2,arr3);
    cout<<"\nAfter addition -> ";
    for(int i=0;i<arr3.size();i++){
        cout<<arr3[i]<<" ";
    }
}