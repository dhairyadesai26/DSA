class Solution {
public:
     string invert(string s){
        for(char &c :s){
            c=(c=='0')?'1':'0';

        }
        return s;
     }
     string solve(int n){
        if(n==1){
            return "0";
        }
       string prev=solve(n-1);
       string rev=prev;
       reverse(rev.begin(),rev.end());
       return prev+"1"+invert(rev);




     }
    char findKthBit(int n, int k) {
    string    result=solve(n);
      return result[k-1];

    }
};