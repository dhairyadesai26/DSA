1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        int n=words.size();
5        int sum=0;
6        string s="";
7        for(int i=0;i<n;i++){
8            int m=words[i].size();
9          for(int j=0;j<m;j++){
10              sum+=weights[words[i][j]-'a'];
11
12          }
13          sum=sum%26;
14          s+=(char)('z'-sum);
15          sum=0;
16        }
17        return s;
18
19    }
20};