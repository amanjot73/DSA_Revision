#include<bits/stdc++.h>
using namespace std;
int main() {
    string a = "{{}}}}";
    if(a.length() %2 != 0){
        cout<<"Not Possible";
        return 0;
    }
    stack<char>s;
    for(int i=0;i<a.length();i++){
        char  c= a[i];
        if(c== '{'){
            s.push(c);
        }
        else{
            if(s.empty()){
                s.push(c);
                continue;
            }
            char k = s.top();
            if((c== '}' && k == '{')){
                s.pop();
            }
            else{
                s.push(c);
            }

            
        }

    }
    int open = 0 , close = 0;
    while(!s.empty()){
        char k = s.top();
        s.pop();
        if(k ==')' || k == ']' || k == '}'){
            close++;
        }
        else{
            open++;
        }
    }
    int cost = (open+1)/2 + (close+1)/2;
    cout<<cost;




}