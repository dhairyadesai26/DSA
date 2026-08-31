class Solution {
public:
    
    int solve(int i,int j,string &x,string &y, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(x[i]==y[j]){
            return dp[i][j]=solve(i-1,j-1,x,y,dp);
        }
        return dp[i][j]=1+min({solve(i,j-1,x,y,dp),solve(i-1,j,x,y,dp),solve(i-1,j-1,x,y,dp)});




    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,word1,word2,dp);       
    }
};