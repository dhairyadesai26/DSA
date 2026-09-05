class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> smallest(n);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
             mini=min(mini,nums[i]);
             smallest[i]=mini;
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-smallest[i]<=k){
                return i;
            }
        }
        return -1;
        
    }
};