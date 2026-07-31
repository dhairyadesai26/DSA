class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        vector<int> temp(st.begin(),st.end());
        nums=temp;
        return nums.size();



    }
};