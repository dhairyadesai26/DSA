class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
       int top=x;
       int bottom=x+k-1;
      
         while(top<bottom){
            for(int j=y;j<y+k;j++){
            swap(grid[top][j],grid[bottom][j]);
            }
         
         top++;
         bottom--;
         }
       

    return grid;
    }
};