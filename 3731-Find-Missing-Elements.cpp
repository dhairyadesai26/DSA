class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        for(int i=mini+1;i<maxi;i++){
            bool flag=false;
            for(int j=0;j<n;j++){
                if(i!=nums[j]){
                    flag=true;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);

            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};