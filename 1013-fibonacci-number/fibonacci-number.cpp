class Solution {
public:
 int fb(int n,vector<int> &dp){
    if(n==0) return 0;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
 }
    int fib(int n) {
        vector<int> dp(n+1);
     return fb(n,dp);

    }
};