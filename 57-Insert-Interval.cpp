class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        
        intervals.push_back({newInterval[0],newInterval[1]});
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        vector<vector<int>> result;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=0;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                result.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
       
        }
        result.push_back({start,end});
        return result;
        


        
    }
};