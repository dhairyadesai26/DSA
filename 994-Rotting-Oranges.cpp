class Solution {
public:
    int m,n;
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int minutes=0;
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            bool rottenThisMinute=false;
            while(size--){
            pair<int,int> curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            for(int i=0;i<4;i++){
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    rottenThisMinute=true;
                   
                }
            }
            }
            if(rottenThisMinute){
                minutes++;
            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minutes;

        
    }
};