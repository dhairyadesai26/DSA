1class Solution {
2public:
3    string processStr(string s) {
4        string result="";
5        int n=s.length();
6        for(int i=0;i<n;i++){
7             if(s[i]>='a' && s[i]<='z'){
8                result+=s[i];
9             }
10           else  if(s[i]=='*'){
11                 if(!result.empty()){
12                 result.pop_back();
13                 }
14             }
15           else  if(s[i]=='#'){
16                 result+=result;
17             }
18             else{
19                reverse(result.begin(),result.end());
20             }
21
22        }
23        return result;
24    }
25};