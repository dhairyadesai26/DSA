class Solution {
public:
typedef long long ll;
    long long countCommas(long long n) {
        ll result=0;
        ll start=1000;
        while(start<=n){
            result+=(n-start+1);
            start*=1000;
        }
        return result;
        
    }
};