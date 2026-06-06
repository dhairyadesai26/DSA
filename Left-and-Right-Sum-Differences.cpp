1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n=nums.size();
5        vector<int> left(n,0);
6        vector<int> right(n,0);
7        vector<int> ans(n,0);
8        int ls=0;
9        int rs=0;
10        for(int i=0;i<n;i++){
11            left[i]=ls;
12            ls+=nums[i];
13           
14        }
15        
16         for(int i=n-1;i>=0;i--){
17            right[i]=rs;
18            rs+=nums[i];
19        }
20        for(int i=0;i<n;i++){
21            ans[i]=(abs(left[i]-right[i]));
22        }
23        return ans;
24
25    }
26};