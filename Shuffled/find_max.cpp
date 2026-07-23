#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>vec , int &result){
    int s = 0,e = vec.size()-1;
    while(s<=e){
        int m = (s+e)/2;
        if(vec[m]<vec[e]){//right side sorted
            result = max(result,vec[e]);
            e = m-1;

        }
        else{
            result = max(result,vec[m]);
            s = m+1;
        }
    }
}
int main() {
    vector<int> vec = {7,2,3,4,5,6};
    int result = INT_MIN;
    solve(vec,result);
    cout<<result;


}