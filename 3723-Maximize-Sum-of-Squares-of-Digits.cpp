class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        if(sum>num * 9){
            return "";
        }
        int count=sum / 9;
        int rem=sum % 9;

        for(int i=0;i<count;i++){
             ans.push_back('9');
             num--;
        }
        if(num>0){
        ans.push_back(rem + '0');
        num=num-1;
        }
        while(num>0){
            ans.push_back('0');
            num--;
        }
        return ans;
        
    }
};