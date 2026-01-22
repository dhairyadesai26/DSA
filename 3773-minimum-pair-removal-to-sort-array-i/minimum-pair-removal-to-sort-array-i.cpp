class Solution {
public:
    bool isSorted(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while(nums.size() > 1){
            if(isSorted(nums)) break;

            int minSum = INT_MAX;
            int idx = 0;

            // find adjacent pair with minimum sum
            for(int i=0;i+1<nums.size();i++){
                if(nums[i] + nums[i+1] < minSum){
                    minSum = nums[i] + nums[i+1];
                    idx = i;
                }
            }

            // merge the pair
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);

            count++;
        }

        return count;
    }
};
