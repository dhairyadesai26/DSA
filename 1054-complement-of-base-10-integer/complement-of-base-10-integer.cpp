class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        string s = bitset<32>(n).to_string();
        int m = s.size();
        int i = 0;

       
        while(i < m && s[i] != '1'){
            i++;
        }

        for(int j = i; j < m; j++){
            if(s[j] == '1'){
                s[j] = '0';
            }
            else{
                s[j] = '1';
            }
        }

        return stoi(s, nullptr, 2);
    }
};