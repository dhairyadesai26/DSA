class Solution {
public:

    int solve(string s, char start){
        int count = 0;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i] != start){
                count++;
            }
            start = (start=='0') ? '1' : '0';
        }

        return count;
    }

    int minOperations(string s) {

        return min(solve(s,'0'), solve(s,'1'));

    }
};