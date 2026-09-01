class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]=-1;
            mp2[t[i]]=-1;
        }
        for(int i=0;i<s.length();i++){
            if(mp1[s[i]]!=-1 && mp1[s[i]]!=t[i]){
                return false;
            }
            if(mp2[t[i]]!=-1 && mp2[t[i]]!=s[i]){
                return false;
            }
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];

        }
        return true;

        
    }
};