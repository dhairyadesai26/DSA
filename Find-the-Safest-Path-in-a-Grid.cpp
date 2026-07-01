1class Solution {
2public:
3    
4    int maximumSafenessFactor(vector<vector<int>>& grid) {
5        int n=grid.size();
6        vector<vector<int>>arr(n,vector<int>(n,INT_MAX));
7        vector<vector<int>>vis(n,vector<int>(n,-1));
8        queue<pair<int,int>>q;
9        for(int i=0;i<n;i++)
10        {
11            for(int j=0;j<n;j++)
12            {
13                if(grid[i][j]==1)
14                {
15                    vis[i][j]=1;
16                    arr[i][j]=0;
17                    q.push({i,j});
18                }
19            }
20        }
21        vector<int>da{0,0,-1,1};
22        vector<int>db{1,-1,0,0};
23        while(!q.empty())
24        {
25            auto it=q.front();
26            q.pop();
27            for(int t=0;t<4;t++)
28            {
29                int ni=it.first+da[t];
30                int nj=it.second+db[t];
31                if(ni>=0 && nj>=0 && ni<n && nj<n && vis[ni][nj]==-1 && arr[it.first][it.second]+1<arr[ni][nj])
32                {
33                    vis[ni][nj]=1;
34                    arr[ni][nj]=arr[it.first][it.second]+1;
35                    q.push({ni,nj});
36                }
37            }
38        }
39        
40        priority_queue<pair<int,pair<int,int>>>pq;
41        vector<vector<int>> dist(n,vector<int>(n, INT_MIN));
42
43        dist[0][0] = arr[0][0];
44        pq.push({arr[0][0],{0,0}});
45        
46         while (!pq.empty())
47        {
48            int i = pq.top().second.first;
49            int j=pq.top().second.second;
50            int dis = pq.top().first;
51            pq.pop();
52            for(int t=0;t<4;t++)
53            {
54                int ni=i+da[t];
55                int nj=j+db[t];
56                if(ni>=0 && nj>=0 && ni<n && nj<n)
57                {
58                    int w=arr[ni][nj];
59                    if(min(w,dis)>dist[ni][nj])
60                    {
61                        dist[ni][nj]=min(w,dis);
62                        pq.push({min(w,dis),{ni,nj}});
63                    }
64                }
65            }
66            
67        }
68        return dist[n-1][n-1];
69        
70    }
71};