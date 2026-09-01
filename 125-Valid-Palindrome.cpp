class Solution {
public:
    bool isPalindrome(string s) {
        string x="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                x+=s[i];
            }
        }
        for(int i=0;i<x.length();i++){
             x[i]=tolower(x[i]);
        }
        int i=0;
        int j=x.length()-1;
        while(i<j){
            if(x[i]!=x[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }
};