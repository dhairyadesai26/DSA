class Solution {
public:
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
           nums[i]=pow(nums[i],2);
        }
        sort(nums.begin(),nums.end());
        return accumulate(begin(nums)+ n/2,
        end(nums),0ll)- accumulate(begin(nums),begin(nums)+n/2,0ll);

        

        

        
    }
};