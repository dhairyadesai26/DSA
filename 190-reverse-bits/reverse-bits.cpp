class Solution {
public:
    int reverseBits(int n) {
     string s =bitset<32>(n).to_string(); 

        int m=s.size();
        int i=0;
        int j=m-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        n=stoll(s,0,2);
        return n;
    }
};