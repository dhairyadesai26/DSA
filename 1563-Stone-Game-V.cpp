class Solution {
    int n;
public:
    int dp[501][501];
    int prefix[501];
    int solve(int s,int e,vector<int>& stoneValue){
        if(s==e){
            return 0;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int ans=0;
        for(int k=s;k<e;k++){
            int sumL=prefix[k+1]-prefix[s];
            int sumR=prefix[e+1]-prefix[k+1];
            if(sumL<sumR){
                ans=max(ans,sumL+solve(s,k,stoneValue));
            }
            else if(sumL>sumR){
                ans=max(ans,sumR+solve(k+1,e,stoneValue));
            }
            else{
                ans=max(ans,sumL+max(solve(s,k,stoneValue),solve(k+1,e,stoneValue)));
            }
        }

      return dp[s][e]=ans;

    }
    int stoneGameV(vector<int>& stoneValue) {
         n=stoneValue.size();
         prefix[0]=0;
         memset(dp,-1,sizeof(dp));
         for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+stoneValue[i];

         }
         return solve(0,n-1,stoneValue);


    }
};