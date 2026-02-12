class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<char,int> freq;

            for(int j = i; j < n; j++) {
                freq[s[j]]++;

                int f = freq[s[j]];
                bool ok = true;

                for(auto &p : freq) {
                    if(p.second != f) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};
