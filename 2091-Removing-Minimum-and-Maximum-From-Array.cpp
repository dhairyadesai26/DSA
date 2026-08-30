class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

int maxi = INT_MIN;
int mini = INT_MAX;

int maxIndex = -1;
int minIndex = -1;

for(int i = 0; i < n; i++){
    if(nums[i] > maxi){
        maxi = nums[i];
        maxIndex = i;
    }

    if(nums[i] < mini){
        mini = nums[i];
        minIndex = i;
    }
}

int fromFront = max(maxIndex, minIndex) + 1;

int fromBack = n - min(maxIndex, minIndex);

int mixed1 = maxIndex + 1 + (n - minIndex);

int mixed2 = minIndex + 1 + (n - maxIndex);

return min({fromFront, fromBack, mixed1, mixed2});
    }
};