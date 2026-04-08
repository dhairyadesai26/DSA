class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int mod = 1000000007;

        for(int i = 0; i < m; i++) {
            int j = queries[i][0];   // start index

            while(j <= queries[i][1]) {
                nums[j] = (1LL * nums[j] * queries[i][3]) % mod;
                j += queries[i][2];  // step update (IMPORTANT)
            }
        }

        int a = 0;
        for(int i = 0; i < n; i++) {
            a ^= nums[i];
        }

        return a;
    }
};