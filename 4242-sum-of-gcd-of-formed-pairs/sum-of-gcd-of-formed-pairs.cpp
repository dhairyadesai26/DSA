class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
          vector<int> prefixGcd(n);
        int mxi=0;
        for(int i=0;i<n;i++){
             mxi=max(mxi,nums[i]);
             prefixGcd[i]=gcd(nums[i],mxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        int l=0;
        int r=n-1;
        while(l<r){
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;

    }
};