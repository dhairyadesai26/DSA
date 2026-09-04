class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> largest(n);
        vector<int> smallest(n);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            largest[i]=maxi;       
        }
         for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            smallest[i]=mini;       
        }
        for(int i=0;i<n;i++){
            if(largest[i]-smallest[i]<=k){
                return i;
            }
        }
        return -1;

        
    }
};