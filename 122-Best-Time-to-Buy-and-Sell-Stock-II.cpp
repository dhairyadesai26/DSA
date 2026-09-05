class Solution {
public:
    int dp[30001][2];
    int solve(int i,vector<int>& prices,int buy){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1){
          return dp[i][buy];
        }
        int ans=0;
        if(buy){
            int take=-prices[i]+solve(i+1,prices,0);
            int notTake=solve(i+1,prices,1);
            ans=max(take,notTake);
        }
        else{
            int sell=prices[i]+solve(i+1,prices,1);
            int notSell=solve(i+1,prices,0);
            ans=max(sell,notSell);
        }
        return dp[i][buy]=ans;


    }
    
    
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
    memset(dp,-1,sizeof(dp));
   
    return solve(0,prices,1);
       
        

        
    }
};