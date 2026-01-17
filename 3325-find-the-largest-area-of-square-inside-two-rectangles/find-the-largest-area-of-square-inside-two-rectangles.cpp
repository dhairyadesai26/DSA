class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
           int n=bottomLeft.size();
           long long area=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int x1=bottomLeft[i][0];
                    int y1=bottomLeft[i][1];
                    int x2=topRight[i][0];
                    int y2=topRight[i][1];
                       int x3=bottomLeft[j][0];
                    int y3=bottomLeft[j][1];
                    int x4=topRight[j][0];
                    int y4=topRight[j][1];
                    int side1=min(x2,x4)-max(x1,x3);
                    int side2=min(y2,y4)-max(y1,y3);
                    if(side1>0 && side2>0){
                        int side=min(side1,side2);
                        area=max(side*1LL*side,area);

                    }
                }
            }
            return area;
    }
};