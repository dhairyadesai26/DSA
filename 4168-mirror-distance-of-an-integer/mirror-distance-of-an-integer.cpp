class Solution {
public:
   int reverse(int n){
    int reversed=0;
    while(n!=0){
        int ld=n%10;
         reversed=reversed*10+ld;
         n=n/10;
    }
    return reversed;
   }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};