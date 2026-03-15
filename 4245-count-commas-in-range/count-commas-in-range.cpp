class Solution {
public:
    int countCommas(int n) {
        long long mod = 1000000007;
        if(n<1000){
            return 0;
        }
        return (n-999);
       
    }
};