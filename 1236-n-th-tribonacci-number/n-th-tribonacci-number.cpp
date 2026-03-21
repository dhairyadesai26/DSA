class Solution {
    int dp[1001];

    int solve(int i){
        if(i <= 1){
            return i;
        }
        if(i == 2){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] = solve(i-1) + solve(i-2) + solve(i-3);
    }

public:
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};