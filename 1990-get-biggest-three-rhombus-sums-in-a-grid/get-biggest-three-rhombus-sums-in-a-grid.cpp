class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans;
       set<int> sums;
     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sums.insert(grid[i][j]);

                for(int k=1;k<min(n,m);k++){
                     if(i-k<0 || i+k>=n || j-k<0 || j+k>=m)
         break;
          int sum=0;
          int r=i-k,c=j;
        for(int d=0;d<k;d++){
            sum+=grid[r+d][c+d];

        }
         r=i,c=j+k;
        for(int d=0;d<k;d++){
            sum+=grid[r+d][c-d];

        }
         r=i+k,c=j;
        for(int d=0;d<k;d++){
            sum+=grid[r-d][c-d];

        }
         r=i,c=j-k;
        for(int d=0;d<k;d++){
            sum+=grid[r-d][c+d];

        }
      sums.insert(sum);


                }
            }
        }
        auto it=sums.rbegin();
       for(int i=0;i<3 && it!=sums.rend() ;i++,it++){
        ans.push_back(*it);
           
       }
       return ans;
    }
};