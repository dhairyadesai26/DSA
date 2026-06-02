1class Solution {
2public:
3    int earliestFinishTime(vector<int>& landStartTime,
4                           vector<int>& landDuration,
5                           vector<int>& waterStartTime,
6                           vector<int>& waterDuration) {
7
8        int ans = INT_MAX;
9
10        int m = landStartTime.size();
11        int n = waterStartTime.size();
12
13        for (int i = 0; i < m; i++) {
14            for (int j = 0; j < n; j++) {
15
16                
17                int finishLand = landStartTime[i] + landDuration[i];
18                int startWater = max(finishLand, waterStartTime[j]);
19                ans = min(ans, startWater + waterDuration[j]);
20
21              
22                int finishWater = waterStartTime[j] + waterDuration[j];
23                int startLand = max(finishWater, landStartTime[i]);
24                ans = min(ans, startLand + landDuration[i]);
25            }
26        }
27
28        return ans;
29    }
30};