class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto &it :mp){
            auto &v=it.second;
            if(v.size()>=3){
            for(int i = 0; i + 2 < v.size(); i++){
            int dist = 2 * (v[i+2] - v[i]);
            mini = min(mini, dist);
        }
            }
        }
        return mini==INT_MAX?-1:mini;
    
    }
};