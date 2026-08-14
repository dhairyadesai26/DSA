class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int ans=0;
        int left=0;
        unordered_map<char,int> fq;
        int count=0;
        
        for(int right=0;right<n;right++){
            fq[s[right]]++;
            while(fq[s[right]]>2 ){
                 fq[s[left]]--;
                 left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};