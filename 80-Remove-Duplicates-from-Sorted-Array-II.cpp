class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        int count=1;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                count++;
            }
            else{
                count=1;
            }
            if(count<=2){
                nums[k]=nums[i];
                k++;

            }
            

        }
        nums.resize(k);
        return nums.size();

        
        
    }
};