class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> a(nums.begin(), nums.end());
        vector<int> left(n), right(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        right[n - 1] = -1;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;

        int badPairs = 0;
        for (int i = 0; i + 1 < n; i++) {
            pq.push({a[i] + a[i + 1], i});
            if (a[i] > a[i + 1]) badPairs++;
        }

        int ops = 0;

        while (badPairs > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            if (!alive[i] || right[i] == -1) continue;
            int j = right[i];
            if (!alive[j] || a[i] + a[j] != sum) continue;

            int L = left[i];
            int R = right[j];
            if (L != -1 && a[L] > a[i]) badPairs--;
            if (a[i] > a[j]) badPairs--;
            if (R != -1 && a[j] > a[R]) badPairs--;
            a[i] += a[j];
            alive[j] = false;
            right[i] = R;
            if (R != -1) left[R] = i;
            if (L != -1 && a[L] > a[i]) badPairs++;
            if (R != -1 && a[i] > a[R]) badPairs++;

            if (L != -1) pq.push({a[L] + a[i], L});
            if (R != -1) pq.push({a[i] + a[R], i});

            ops++;
        }

        return ops;
    }
};
