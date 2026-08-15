class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool nonZero=false;
        int a=0;
        for(int x:nums){
            a^=x;
            if(x!=0){
                nonZero=true;
            }
        }
        if(a!=0){
            return n;
        }
        if(nonZero){
            return n-1;
        }
        return 0;
    }
};