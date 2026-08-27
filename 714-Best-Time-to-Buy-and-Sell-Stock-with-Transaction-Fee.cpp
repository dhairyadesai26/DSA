class Solution {
public:
    int dp[50001][2];
    int solve(int i,vector<int>& prices,int fee,int buy){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        //take(buy)
        //if bought then sellat later day so profit=buy-sell then subtracting the transaction fee
        // we will do sell as flag if sell is false then we cannot buy and if flag is true we can buy vbecause it is already sold 
        int profit=0;
        if(buy){
          int take = -prices[i] + solve(i + 1, prices, fee, 0);
          int notTake=solve(i+1,prices,fee,1);
          profit=max(take,notTake);
        }
        else{
          int sell = prices[i] -fee+solve(i + 1, prices, fee, 1);
          int notSell=solve(i+1,prices,fee,0);
          profit=max(sell,notSell);



        }

        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,fee,1);
        



    }
};