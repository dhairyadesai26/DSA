class Solution {
public:
    int getdigitSum(int n){
        int sum=0;
        while(n!=0){
            sum+=(n % 10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> afterSorted(nums);
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        auto lambda=[&](int num1,int num2){
            int dsum1=getdigitSum(num1);
            int dsum2=getdigitSum(num2);
            if(dsum1!=dsum2){
                return dsum1<dsum2;
            }
            return num1<num2;


        };
        sort(afterSorted.begin(),afterSorted.end(),lambda);
        int swaps=0;
        for(int i=0;i<nums.size();i++){
            int expectedVal=afterSorted[i];
            int currVal=nums[i];
            if(currVal==expectedVal) continue;
            int idx=mp[expectedVal];
            nums[i]=expectedVal;
            nums[idx]=currVal;
            mp[expectedVal]=i;
            mp[currVal] = idx;
            swaps++;
        }
        return swaps;

        
        
    }
};