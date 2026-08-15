class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long totalCost=0;
        int left=0;
        int right=n-1;
        for(int i=0;i<candidates && left<=right;i++){
            pq.push({costs[left],left});
            left++;
        }
        for(int i=0;i<candidates && left<=right;i++){
            pq.push({costs[right],right});
            right--;
        }
        while(k--){
          auto top=pq.top();
          pq.pop();
          int cost=top.first;
          int index=top.second;
          totalCost+=cost;
          if(index<left){
             if(left<=right){
                pq.push({costs[left],left});
                left++;
             }
          }
          else{
            if(left<=right){
                pq.push({costs[right],right});
                right--;

            }

          }
        }
        return totalCost;

    }
};