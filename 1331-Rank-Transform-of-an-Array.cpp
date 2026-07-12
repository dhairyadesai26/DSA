class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        vector<int> temp(s.begin(),s.end());
        int n=temp.size();
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0;i<n;i++){
            mp[temp[i]]=rank;
            rank++;
            
             }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};