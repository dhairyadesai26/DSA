1class Solution {
2public:
3vector<int> countsort(vector<int>& arr) {
4    int n = arr.size();
5
6    int maxval = 0;
7    for (int i = 0; i < n; i++)
8        maxval = max(maxval, arr[i]);
9
10    vector<int> cntArr(maxval + 1, 0);
11
12   
13    for (int i = 0; i < n; i++)
14        cntArr[arr[i]]++;
15
16
17    for (int i = 1; i <= maxval; i++)
18        cntArr[i] += cntArr[i - 1];
19
20  
21    vector<int> ans(n);
22    for (int i = n - 1; i >= 0; i--) {
23        ans[cntArr[arr[i]] - 1] = arr[i];
24        cntArr[arr[i]]--;
25    }
26
27    return ans;
28}
29    int maxIceCream(vector<int>& costs, int coins) {
30     costs= countsort(costs);
31        int n=costs.size();
32        int count=0;
33        long long money=coins;
34        for(int i=0;i<n;i++){
35            if(money>=costs[i]) {
36                count++;
37            }
38            money=money-costs[i];
39        }
40        return count;
41    }
42};