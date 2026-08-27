class Solution {
public:

    string result = "";

    void solve(int i,
               string& current_s,
               const string& target,
               vector<int>& count,
               bool isGreater) {

        if (i == target.length()) {

            if (isGreater) {
                if (result == "" || current_s < result) {
                    result = current_s;
                }
            }

            return;
        }

        // If we already have a better answer,
        // no need to explore this branch.
        if (result != "" && isGreater) {
            return;
        }

        int start;

        if (isGreater) {
            start = 0;
        } else {
            start = target[i] - 'a';
        }

        for (int j = start; j < 26; j++) {

            if (count[j] > 0) {

                count[j]--;

                current_s.push_back(j + 'a');

                bool newIsGreater =
                    isGreater || (j > target[i] - 'a');

                solve(i + 1,
                      current_s,
                      target,
                      count,
                      newIsGreater);

                current_s.pop_back();

                count[j]++;
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        result = "";

        string current_s = "";

        solve(0, current_s, target, count, false);

        return result;
    }
};