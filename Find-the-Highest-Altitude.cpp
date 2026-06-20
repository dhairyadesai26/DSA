1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        vector<int> result;
5        int gainH=0;
6        int maxH=0;
7        result.push_back(0);
8        for(int i=0;i<gain.size();i++){
9            gainH=gainH+gain[i];
10            result.push_back(gainH);
11        }
12        for(int i=0;i<result.size();i++){
13    maxH=max(maxH,result[i]);
14        }
15        return maxH;
16    }
17};