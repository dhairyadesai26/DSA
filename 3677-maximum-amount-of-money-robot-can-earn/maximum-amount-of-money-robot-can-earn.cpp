class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        // dp[i][j][k] → max coins at (i,j) using k neutralizations
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        // Start
        for(int k = 0; k < 3; k++) {
            if(coins[0][0] < 0 && k > 0)
                dp[0][0][k] = 0; // neutralize
            else
                dp[0][0][k] = coins[0][0];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k <= 2; k++) {

                    if(i == 0 && j == 0) continue;

                    int val = coins[i][j];

                    // From top
                    if(i > 0) {
                        // take normally
                        if(dp[i-1][j][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);

                        // neutralize if negative
                        if(val < 0 && k > 0 && dp[i-1][j][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    }

                    // From left
                    if(j > 0) {
                        // take normally
                        if(dp[i][j-1][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);

                        // neutralize if negative
                        if(val < 0 && k > 0 && dp[i][j-1][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }

        // Answer = max over k = 0,1,2
        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};