class Solution {
public:
    long long count(vector<int>& coins, long long x) {
        long long cnt = 0;
        int n = coins.size();

        for(int i = 1; i < (1 << n); i++) {
            long long lcmVal = 1;
            int setBits = 0;

            for(int j = 0; j < n; j++) {
                if(((i >> j) & 1) == 1) {
                    setBits++;
                    lcmVal = lcm(lcmVal, coins[j]);

                    if(lcmVal > x)
                        break;
                }
            }

            if(setBits % 2 == 1) {
                cnt += x / lcmVal;
            }
            else {
                cnt -= x / lcmVal;
            }
        }

        return cnt;
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * coins[0] * k;
        long long ans = high;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(count(coins, mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};