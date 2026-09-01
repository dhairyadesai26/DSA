class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=s.length();
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        
        string result="";
        int i=0,j=0;
        while( i<s.length()){                                         
                if(s[i]!=' '){
                    result+=s[i];
                }
                else{
                if(j>=pattern.length()){
                    return false;
                }
                if (mp1.count(pattern[j]) && mp1[pattern[j]] != result)
                    return false;

                if (mp2.count(result) && mp2[result] != pattern[j])
                       return false;

                mp1[pattern[j]]=result;
                mp2[result]=pattern[j];
                j++;
                result="";
                }
                i++;
          }
          if(result!=""){
            if(j>=pattern.length()) return false;
            if (mp1.count(pattern[j]) && mp1[pattern[j]] != result)
                    return false;

            if (mp2.count(result) && mp2[result] != pattern[j])
                       return false;

            mp1[pattern[j]]=result;
            mp2[result]=pattern[j];
            j++;

          }
          return j==pattern.length();
        
       
    }
};