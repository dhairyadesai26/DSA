class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> result;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int prev1=nums[0];
        int prev2=nums[1];
        for(int i=2;i<n;i++){
             if(prev1>prev2){
                arr1.push_back(nums[i]);
                prev1=nums[i];
             }
             else{
                arr2.push_back(nums[i]);
                prev2=nums[i];

             }
        }
        for(int i=0;i<arr1.size();i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            result.push_back(arr2[i]);
        }
        return result;

        
    }
};