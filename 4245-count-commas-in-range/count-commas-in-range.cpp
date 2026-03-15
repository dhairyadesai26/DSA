class Solution {
public:
    int countCommas(int n) {
        long long mod = 1000000007;
        if(n<1000){
            return 0;
        }
        return ( (n % mod - 999 % mod + mod) % mod );
       
    }
};