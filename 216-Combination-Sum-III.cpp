class Solution {
public:
void solve(int i,int k,int sum,int n,vector<int> &subset,vector<vector<int>> &ans){
    if(k<0) return;
    if(sum==n){
        if(k==0){
            ans.push_back(subset);
        }
        return;
    }
    if(i==10) return ;

    sum+=i;
    subset.push_back(i);
    solve(i+1,k-1,sum,n,subset,ans);
    sum-=i;
    subset.pop_back();

    solve(i+1,k,sum,n,subset,ans);


}
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> ans;
      vector<int> subset;
      solve(1,k,0,n,subset,ans);
      return ans;
    }
};