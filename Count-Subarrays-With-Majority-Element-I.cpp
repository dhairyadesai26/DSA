1class Solution {
2public:
3 
4    int countMajoritySubarrays(vector<int>& nums, int target) {
5        int n = nums.size();
6
7    vector<int> pref(n + 1, 0);
8
9    for (int i = 0; i < n; i++) {
10        pref[i + 1] = pref[i] + (nums[i] == target);
11    }
12
13    int ans = 0;
14
15    for (int i = 0; i < n; i++) {
16        for (int j = i; j < n; j++) {
17
18            int cnt = pref[j + 1] - pref[i];
19            int len = j - i + 1;
20
21            if (2 * cnt > len)
22                ans++;
23        }
24    }
25    return ans;
26    }
27};