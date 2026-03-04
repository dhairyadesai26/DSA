class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int sp = 0;
        int r = mat.size();
        int c = mat[0].size();

        for(int i = 0; i < r; i++) {
            int rowcnt = 0;
            int colIndex = -1;

           
            for(int j = 0; j < c; j++) {
                if(mat[i][j] == 1) {
                    rowcnt++;
                    colIndex = j;
                }
            }

          
            if(rowcnt == 1) {
                bool flag = true;

                
                for(int k = 0; k < r; k++) {
                    if(k != i && mat[k][colIndex] == 1) {
                        flag = false;
                        break;
                    }
                }

                if(flag) sp++;
            }
        }

        return sp;
    }
};