class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> fq;
        int ans=0;
        int left=0;
        for(int right=0;right<n;right++){
             fq[nums[right]]++;
             while(fq[nums[right]]>k){
                fq[nums[left]]--;
                left++;
             }
             ans=max(ans,right-left+1);

              
            
        }
        return ans;
        
    }
};