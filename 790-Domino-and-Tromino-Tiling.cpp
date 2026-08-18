class Solution {
public:
    const long long mod=1e9+7;
    int dp[1001];
    int solve(int m){
        if(m==0){
            return 1;
        }
        if(m==1){
            return 1;
        }
        if(m==2){
            return 2;
        }

        if(dp[m]!=-1){
           return dp[m];
        }

        return dp[m]=(2LL*solve(m-1)+solve(m-3)) % mod;
    }
    
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);



        
    }
};