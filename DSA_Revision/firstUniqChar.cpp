class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            char k  = s[i];
            int index = (int)k-97;
            arr[index]++;
        }
        for(int i=0;i<s.length();i++){

            char k  = s[i];
            int index = (int)k-97;
            if(arr[index]==1){
                return i;
            }
        }
        return -1;
    }
};