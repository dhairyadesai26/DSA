class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans="";
        int n=s.length();
        int charinsection=2*(numRows-1);
        for(int currRow=0;currRow<numRows;currRow++){
            int idx=currRow;
            while(idx<n){
                ans+=s[idx];
                if(currRow!=0 && currRow!=numRows-1){
                    int charinbetween=charinsection-2*(currRow);
                    int secondindex=idx+charinbetween;
                    if(secondindex<n){
                        ans+=s[secondindex];

                    }

                }
                idx+=charinsection;
            }

        }
        return ans;

        
    }
};