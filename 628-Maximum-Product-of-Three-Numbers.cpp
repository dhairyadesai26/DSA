class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngarr;
        vector<int> psarr;

    for (int i = 0; i < n; i++) {
       if (nums[i] < 0)
        ngarr.push_back(nums[i]);
        else
        psarr.push_back(nums[i]);
         }

      sort(psarr.rbegin(), psarr.rend());   
      sort(ngarr.begin(), ngarr.end());     

      int ans = INT_MIN;


      if (psarr.size() >= 3) {
      ans = max(ans, psarr[0] * psarr[1] * psarr[2]);
      }


      if (ngarr.size() >= 2 && psarr.size() >= 1) {
      ans = max(ans, ngarr[0] * ngarr[1] * psarr[0]);
      }


      if (psarr.empty()) {
      sort(ngarr.rbegin(), ngarr.rend());  
      ans = ngarr[0] * ngarr[1] * ngarr[2];
       }

     return ans;
    }
};