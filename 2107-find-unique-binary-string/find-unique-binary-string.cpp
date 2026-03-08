class Solution {
public:

    void generateBinaryStrings(int n, string current_string, vector<string>& result) {
        if (current_string.length() == n) {
            result.push_back(current_string);
            return;
        }

        generateBinaryStrings(n, current_string + "0", result);
        generateBinaryStrings(n, current_string + "1", result);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        vector<string> unique_strings;
        generateBinaryStrings(n, "", unique_strings);

        vector<string> difference;

        sort(unique_strings.begin(), unique_strings.end());
        sort(nums.begin(), nums.end());

        set_difference(
            unique_strings.begin(), unique_strings.end(),
            nums.begin(), nums.end(),
            inserter(difference, difference.begin())
        );

        return difference[0];
    }
};