class Solution {
public:
 int solve(int i){
    string s="";
    while(i!=0){
        s+=char(i%2);
        i=i/2;

    }

    int n=s.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='\1'){
            count++;
        }
    }
    return count;
 }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
           ans.push_back(solve(i));
        }
        return ans;
    }
};