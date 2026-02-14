class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     int n=digits.size();
     int c=1;
     int sum=0;
     for(int i=n-1;i>=0;i--){
     sum=digits[i]+c;
     digits[i]=sum%10;
     c=sum/10;
        
     }
     if(c==1){
        digits.insert(digits.begin(),1);
     }
     return digits;
       
    }
};