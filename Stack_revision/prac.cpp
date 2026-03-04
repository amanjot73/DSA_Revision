// Valid Parenthesis

#include<bits/stdc++.h>
using namespace std;
int main() {
    string a = "{[()]}{}";
    stack<int> s;

    for(int i=0;i<a.length();i++){
        char k = a[i];
        if(k == '(' || k == '{' || k== '['){
            s.push(k);
        }
        else{
            if(s.empty()){
                cout<<"Invalid Parenthesis";
                return 0;
            }
            else{
                char t = s.top();
                if( (t=='(' && k == ')') || (t=='{' && k == '}')  || (t=='[' && k == ']')){
                    s.pop();
                }
                else{

                    s.push(k);
                }
            }
        }
    }
    if(s.empty()){
        cout<<"Valid";
    }
    else{
        cout<<"Not Valid";
    }
}

// Cost to make parenthesis valid

#include<bits/stdc++.h>
using namespace std;
int main() {
    string a = "{{}{{{}";
    if(a.length() % 2 != 0){
        cout<<"Impossible to validate";
        return 0;
    }
    stack<int>s ;
    for(int i=0;i<a.length();i++){
        char c = a[i];
        if(c == '{'){
            s.push(c);
        }
        else{
            if(s.empty()){
                s.push(c);
                continue;
            }
            char t = s.top();
            if(t == '{' && c == '}'){
                s.pop();
            }
            else{
                s.push(c);
            }
        }

    } 
    int open = 0, close = 0;
    while(!s.empty()){
        if(s.top() == '{'){
            open++;
        }
        else{
            close++;
        }
        s.pop();
    }
    int cost = (open+1)/2 + (close+1)/2;
    cout<<"Total cost will be -> "<<cost;
    
}

// Celebrity Problem

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> arr = {{0,1,1},{1,0,1},{0,0,0}};
    stack<int>s;
    for(int i=0;i<arr.size();i++){
        s.push(i);
    }
    while(s.size()>1){
        int one = s.top();
        s.pop();
        int two = s.top();
        s.pop();
        if(arr[one][two]){
            s.push(two);
        }
        else{
            s.push(one);
        }
    }
    cout<<"The celebrity is -> " << s.top();
}



// find next smaller no.

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {8,4,9,6,2};
    stack<int>s;
    vector<int>result(arr.size());
    s.push(-1);
    for(int i= arr.size()-1;i>=0;i--){
        int element = arr[i];
        while(s.top()>element){
            s.pop();
        }
        result[i] = s.top();
        s.push(element);
    }
    for(auto &i:result){
        cout<<i<<" ";
    }
}

// max rectangle in histogram
#include<bits/stdc++.h>
using namespace std;
vector<int>next (vector<int>a){
    vector<int>result(a.size());
    stack<int>s;
    s.push(-1);
    for(int i = a.size()-1;i>=0;i--){
        int element = a[i];
        while(s.top() !=-1 && a[s.top()]>=element){
            s.pop();
        }
        result[i] = s.top();
        s.push(i);
    }
    return result;

}
vector<int>prev (vector<int>a){
    vector<int>result(a.size());
    stack<int>s;
    s.push(-1);
    for(int i = 0;i<a.size();i++){
        int element = a[i];
        while(s.top() !=-1 && a[s.top()]>=element){
            s.pop();
        }
        result[i] = s.top();
        s.push(i);
    }
    return result;

}
int main() {
    vector<int>a = {1,2,3,4,5};
    vector<int>n;
    n = next(a);
    for(auto &i:n){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>p;
    p = prev(a);
    for(auto &i:p){
        cout<<i<<" ";
    }
    int area = INT_MIN;
    for(int i=0;i<a.size();i++){
        if(n[i] == -1){
            n[i] = a.size();
        }
        int length = a[i];
        int breadth = n[i] - p[i] - 1;
        int k = length*breadth;
        area = max(area,k);

    }
    cout<<"\nArea with max area is -> "<<area;
}