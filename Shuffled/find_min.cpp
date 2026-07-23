#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>vec,int &result){
    int start = 0;
    int end = vec.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(vec[mid]<vec[end]){
            result = min(result,vec[mid]);
            end = mid-1;
        }
        else{
            result = min(result,vec[start]);
            start = mid+1;
        }
    }
}
int main() {
    int result = INT_MAX;
    vector<int>vec = {4,5,6,7,1,2};
    solve(vec,result);
    cout<<result;

}