class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k!=0){
        vector<vector<int>> temp=grid;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j==c-1 && i!=r-1){
                    temp[i+1][0]=grid[i][j];
                    break;
                }
                if(i==r-1 && j==c-1){
                    temp[0][0]=grid[i][j];

                }
                if(j!=c-1){
                temp[i][j+1]=grid[i][j];
                }

            }
        }
        grid=temp;
        k--;
        }
        return grid;
    }
};