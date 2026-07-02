#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>vec = {-4,-2,-11,-3,-5};
    int max1  = INT_MIN;
    int max2 = INT_MIN;
    for(auto &i : vec){
        if(i>max1){
            max2 = max1;
            max1 = i;
        }
        else if(i>max2 && i!=max1){
            max2 = i;
        }
    }
    cout<<max2;

}