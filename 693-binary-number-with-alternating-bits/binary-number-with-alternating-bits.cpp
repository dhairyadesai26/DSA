class Solution {
public:
    bool hasAlternatingBits(int n) {

        string s = bitset<32>(n).to_string();

        int i = 0;
        while(i < 32 && s[i] == '0'){
            i++;
        }

        char prev = s[i];
        i++;

        for(; i < 32; i++){
            if(s[i] == prev){
                return false;
            }
            prev = s[i];
        }

        return true;
    }
};
