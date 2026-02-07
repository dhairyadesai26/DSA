class Solution {

public:
 bool check(vector<int> &nums,int k,int val){
    int n=nums.size();
    for(int i=0;i<=val;i++){
        int smallest=nums[i];
            long long int largest = nums[n - 1 - val + i];
            if (largest <= k * 1LL * smallest) {
                return true;
            }

    }
    return false;
 }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums.back()*1LL<=k*1LL*nums[0]){
            return 0;
        }
        int l=0;
        int r=n-1;
        int ans=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,k,mid)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }


        }
        return ans;

    }
};