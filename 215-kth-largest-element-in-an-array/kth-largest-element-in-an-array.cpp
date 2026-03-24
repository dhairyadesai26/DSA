class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
      int count=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        pq.push(nums[i]);
      }
     while(count!=k-1){
        pq.pop();
        count++;
     }
      return pq.top();

    }
};