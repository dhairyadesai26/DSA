class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(int person,int i,int m,vector<int>& piles){
        if(i>=n) return 0 ;
        if(dp[person][i][m]!=-1){
            return dp[person][i][m];
        }
        int stones=0;
        int result=(person==1)?-1 :INT_MAX;
        for(int x=1;x<=min(2*m,n-i);x++){
        stones+=piles[i+x-1];
        if(person==1){
            result=max(result,stones+solve(0,i+x,max(x,m),piles));
           
        }
        else{
            result=min(result,solve(1,i+x,max(x,m),piles));
        }
        }
        return dp[person][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,0,1, piles);
        
    }
};