class Solution {
public:
    int countCommas(int n) {
        string s=to_string(n);
        int m=s.size();
        if(n<1000){
            return 0;
        }
        return ( n-999);
       
    }
};