class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1 +cost2<=costBoth){
            return (long long)need1*cost1 + (long long)need2*cost2;
        }
        else{
            
            long long both=min(need1,need2);
            long long total=both*(long long)costBoth;
            need1-=both;
            need2-=both;
            if(need1>0){
                total+=min((long long)need1*cost1,(long long)need1*costBoth);
            }
            else{
                total+=min((long long)need2*cost2,(long long)need2*costBoth);
            }
            return total;


        }
        
    }
};