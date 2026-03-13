class Solution {
public:

    bool check(vector<int>& workerTimes, long long t, int h) {
        long long total = 0;

        for (int w : workerTimes) {

            long long l = 0, r = 1e6, best = 0;
            while (l <= r) {
                long long mid = l + (r - l) / 2;
           long long time = (long long)w * mid * (mid + 1)/2 ;
           if (time <= t) {
                    best = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            total += best;

            if (total >= h)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long l = 1, r = 1e18;
        long long result = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;

            if (check(workerTimes, mid, mountainHeight)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};