class Solution {
public:
    string addBinary(string a, string b) {
 int m=a.size()-1;
 int n=b.size()-1;
 int sum=0;
 string result="";
 int c=0;
 while(m>=0 || n>=0){
    int sum=c;
    if(m>=0){
        sum+=(a[m]-'0');
        m--;

    }
     if(n>=0){
        sum+=(b[n]-'0');
        n--;
    }
    result.push_back((sum%2)==0 ?'0':'1');
    c=(sum>1) ? 1:0;

 }
 if(c){
    result.push_back('1');
 }
 reverse(begin(result),end(result));
       return result;

    }
};