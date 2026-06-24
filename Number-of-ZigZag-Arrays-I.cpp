1class Solution {
2public:
3     const int MOD=1e9 +7;
4    int zigZagArrays(int n, int l, int r) {
5       int m=r-l+1;
6       vector<vector<int>> up(n+1,vector<int>(m,0));
7       vector<vector<int>> down(n+1,vector<int>(m,0));
8
9       for(int x=0;x<m;x++){
10          for(int y=0;y<m;y++){
11            if(x==y) continue;
12            if(x<y) up[2][y]=(up[2][y]+1) %MOD;
13            else down[2][y]=(down[2][y]+1) %MOD;
14          }
15           
16       }
17       for(int i=3;i<=n;i++){
18          vector<int> prefUp(m + 1, 0), prefDown(m + 1, 0);
19          for(int v=0;v<m;v++){
20            prefUp[v+1]=(prefUp[v]+up[i-1][v]) %MOD;
21            prefDown[v+1]=(prefDown[v]+down[i-1][v]) %MOD;
22          }
23          for(int y=0;y<m;y++){
24            up[i][y]=prefDown[y];
25             down[i][y]=((prefUp[m] - prefUp[y + 1]) % MOD + MOD) % MOD;
26          }
27       }
28       long long ans=0;
29       if(n==1){
30         ans=m;
31       }
32       else{
33            for(int y=0;y<m;y++){
34                ans=(ans+up[n][y]+down[n][y] )% MOD;
35            }
36       }
37       return ans;
38
39
40    }
41};