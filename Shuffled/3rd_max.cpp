#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>vec = {-1,-4,-24,-5,-3};
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    for(auto &i : vec){
        if(i>max1){
            max3 = max2;
            max2 = max1;
            max1 = i;
        }
        else if(i>max2 && i!= max1){
            max3 = max2;
            max2 = i;
        }
        else if(i>max3 && i!= max2){
            max3 = i;
        }

    }
    cout<<max3;
}