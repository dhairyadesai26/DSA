class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int maxDigit = 0;

        for(int i = 0; i < len; i++){
            if(n[i] - '0' > maxDigit){
                maxDigit = n[i] - '0';
            }
        }
        return maxDigit;
    }
};