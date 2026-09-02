class Solution {
public:
    int hammingWeight(int n) {
    int count=0;
    string x="";
    while(n!=0){
        char temp=(n % 2) +'0';
        x+=temp;
        n/=2;
    }
    for(int i=0;i<x.length();i++){
        if(x[i]=='1'){
            count++;
        }
    }
    return count;

        
    }
};