1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4
5        int n = s.size();
6
7        queue<int> q;
8        q.push(0);
9
10        vector<bool> visited(n, false);
11        visited[0] = true;
12
13        int farthest = 0;
14
15        while (!q.empty()) {
16
17            int i = q.front();
18            q.pop();
19
20            int start = max(i + minJump, farthest + 1);
21            int end = min(i + maxJump, n - 1);
22
23            for (int j = start; j <= end; j++) {
24
25                if (s[j] == '0' && !visited[j]) {
26
27                    if (j == n - 1)
28                        return true;
29
30                    visited[j] = true;
31                    q.push(j);
32                }
33            }
34
35            farthest = end;
36        }
37
38        return n == 1;
39    }
40};