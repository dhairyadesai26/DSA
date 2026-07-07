class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string x="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                x+=s[i];
            }
        }
        if(x==""){
            return 0;
        }
       long long sum=0;
       for(int i=0;i<x.length();i++){
           sum+=x[i]-'0';
       }
       return sum*stoi(x);
    }
};