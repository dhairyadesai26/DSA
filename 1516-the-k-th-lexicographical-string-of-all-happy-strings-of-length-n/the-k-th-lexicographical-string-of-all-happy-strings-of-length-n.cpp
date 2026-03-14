class Solution {
public:

    void combinations(string &s, int n, vector<string> &ans) {

        if (s.size() == n) {
            ans.push_back(s);
            return;
        }

        for (char c : {'a','b','c'}) {

            if (!s.empty() && s.back() == c)
                continue;

            s.push_back(c);
            combinations(s, n, ans);
            s.pop_back();
        }
    }

    string solve(int n,int k,vector<string> &ans){

        string s="";
        combinations(s,n,ans);

        if(ans.size() < k)
            return "";

        return ans[k-1];
    }

    string getHappyString(int n, int k) {

        vector<string> ans;
        return solve(n,k,ans);
    }
};