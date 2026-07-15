class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven=pow(n,2);
        int sumOdd=pow(n,2) +n;
        return gcd(sumOdd,sumEven);
    }
};