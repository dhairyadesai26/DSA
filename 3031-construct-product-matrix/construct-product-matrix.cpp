class Solution {
public:
const int  MOD=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
   vector<long long> ans;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        ans.push_back(grid[i][j]);
    }
   }
   int size=ans.size();
   vector<long long> left(size,1);
   vector<long long> right(size,1);
   for(int i=1;i<size;i++){
    left[i]=(left[i-1] * ans[i-1]) % MOD;
   }
   for(int i=size-2;i>=0;i--){
    right[i]=(right[i+1]* ans[i+1]) % MOD;
   }
   int k=0;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      grid[i][j]=(left[k]*right[k]) % MOD;
      k++;
    }
   }
   return grid;


    }
};