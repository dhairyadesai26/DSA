class Solution {
public:
    int m,n;
    vector<int> dr={-1,-1,0,1,1,1,0,-1};
    vector<int> dc={0,1,1,1,0,-1,-1,-1};
    int solve(int& i,int&j,vector<vector<int>>& board){
        int count=0;
        for(int k=0;k<8;k++){
             int nr=i+dr[k];
             int nc=j+dc[k];
             if(nr>=0 && nr<m && nc>=0 && nc<n){
                if(board[nr][nc]==1){
                    count++;
                }
             }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
         m=board.size();
         n=board[0].size();
        vector<vector<int>> original = board;
        //live cell having less than two neighbors dies
        // live celltwo or three neighbors lives
        //live cell, more than 3 neighbors dies
        // dead cell with three live neighbors becomes live
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  int count=solve(i,j,original);
                  if(original[i][j]==1){
                  if(count<2 || count>3) board[i][j]=0;
                 
                  }
                  else{
                     if(count==3) board[i][j]=1;
                  }
                  

            }
        }

        
    }
};