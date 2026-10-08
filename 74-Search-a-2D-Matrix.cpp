class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s=0;
        int e=(r*c)-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int row=(mid/c);
            int col=(mid % c);
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
        
    }
};