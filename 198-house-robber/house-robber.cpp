class Solution {

public:
int dp[101];
 int solve(int i,vector<int>& nums){

    int m=nums.size();
     if(i>=m) return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int take=nums[i]+solve(i+2,nums);
    int skip=solve(i+1,nums);
    return dp[i]=max(take,skip);

    
    
 }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();

       
        return solve(0,nums);
        
    }
};