class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;

        unordered_map<int, int> fq;
        unordered_map<int, int> total;

   
       for (int i = 0; i < k; i++) {
         fq[nums[i]]++;
        }

    
       for (auto [x, f] : fq) {
        total[x]++;
        }

       for (int i = k; i < n; i++) {

        fq[nums[i-k]]--;

        if (fq[nums[i-k]] == 0) {
            fq.erase(nums[i-k]);
        }

        fq[nums[i]]++;
        for (auto [x, f] : fq) {
            total[x]++;
        }
    }

    for (auto [x, f] : total) {
        if (f == 1) {
            maxi = max(maxi, x);
        }
    }

    return maxi;
    }
};