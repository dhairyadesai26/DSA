class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int max=*max_element(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            count+=(max-nums[i]);
        }
        return count;


        
    }
};