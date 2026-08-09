class Solution {
public:
    int dp[21][21];

    int solve(vector<int>& nums, int x, int y) {
        if (x > y) return 0;

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        int takeLeft = nums[x] - solve(nums, x + 1, y);
        int takeRight = nums[y] - solve(nums, x, y - 1);

        return dp[x][y] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        int difference = solve(nums, 0, nums.size() - 1);

        return difference >= 0;
    }
};