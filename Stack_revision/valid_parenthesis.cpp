#include<bits/stdc++.h>
using namespace std;
int main() {
    string a = "[({})](([]))";
    stack<char>s;
    for(int i=0;i<a.length();i++){
        char k  = a[i];
        if(k == '(' || k == '[' || k == '{'){
            s.push(k);
        }
        else{
            
            if(s.empty()){
                cout<<"Not Valid";
                return 0;
            }

            char t = s.top();
            if(k == '}' || k == ']' || k == ')'){
                if((k == '}' && t == '{') || (k == ')' && t == '(') || (k == ']' && t == '[')){
                    s.pop();
                }
                else{
                    cout<<"Not Valid";
                    return 0;
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