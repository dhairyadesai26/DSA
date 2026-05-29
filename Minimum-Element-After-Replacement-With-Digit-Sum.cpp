1class Solution {
2public:
3 int solve(int a){
4    int sum=0;
5    while(a!=0){
6        sum+=(a%10);
7        a=a/10;
8    }
9    return sum;
10
11 }
12    int minElement(vector<int>& nums) {
13        int n=nums.size();
14        vector<int> ans;
15        for(int i=0;i<n;i++){
16            ans.push_back(solve(nums[i]));
17        }
18        int mini=INT_MAX;
19        for(int i=0;i<n;i++){
20            mini=min(mini,ans[i]);
21        }
22        return mini;
23
24    }
25};