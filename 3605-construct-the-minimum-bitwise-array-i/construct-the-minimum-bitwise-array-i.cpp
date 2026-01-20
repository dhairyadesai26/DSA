class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int mini = INT_MAX;
            bool found = false;

            for(int j = 0; j < nums[i]; j++){
                if( (j | (j + 1)) == nums[i] ){
                    mini = min(mini, j);
                    found = true;
                }
            }

            if(found)
                ans.push_back(mini);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};
