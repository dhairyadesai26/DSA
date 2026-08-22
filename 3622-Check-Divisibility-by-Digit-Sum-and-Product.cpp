class Solution {
public:
    bool checkDivisibility(int n) {
        int product=1,n_org=n;
        int sum=0;
        while(n!=0){
            int temp=n%10;
            product*=temp;
            sum+=temp;
            n/=10;



        }
        return (n_org % (sum+product))==0;
    }
};