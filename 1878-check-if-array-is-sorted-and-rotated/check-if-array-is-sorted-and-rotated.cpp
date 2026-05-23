class Solution {
public:
    bool check(vector<int>& nums) {
    int n = nums.size();

    vector<int> nums1 = nums;
    sort(nums1.begin(), nums1.end());

    int a = -1;

    // Find rotation amount
    for(int x = 0; x < n; x++) {

        bool found = true;

        for(int i = 0; i < n; i++) {

            if(nums[(i + x) % n] != nums1[i]) {
                found = false;
                break;
            }
        }

        if(found) {
            a = x;
            break;
        }
    }

    // If no valid rotation found
    if(a == -1) {
        return false;
    }

    return true;
}
};