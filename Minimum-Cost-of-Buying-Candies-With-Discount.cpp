1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        int n=cost.size();
5        int sum=0;
6        int count=0;
7        sort(cost.rbegin(),cost.rend());
8        for(int i=0;i<n;i++){
9            if(count==2){
10            
11              count=0;
12              continue;
13
14            }
15            sum+=cost[i];
16            count++;
17        }
18        return sum;
19    }
20};