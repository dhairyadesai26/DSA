class Solution {
public:
    int solve(string x){
        int m=x.size();
        int ans =1;
        for(int i=0;i<m;i++){
            ans*=(x[i]-'0');
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int result=1;
        for(int i=n;i<1000;i++){
            string s=to_string(i);
            int product=solve(s);
            if(product==0){
                return i;
            }
            if(product % t==0){
                 return i;
            }
        }
        return result;
    }
};