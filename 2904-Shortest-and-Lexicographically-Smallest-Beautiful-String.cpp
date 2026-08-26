class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        int ones = 0;

        string result = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // Remove unnecessary characters
            while (left <= right && (ones > k || s[left] == '0')) {

                if (s[left] == '1') {
                    ones--;
                }

                left++;
            }

            // We have exactly k ones
            if (ones == k) {

                string temp = s.substr(left, right - left + 1);

                if (result.empty() ||
                    temp.length() < result.length() ||
                    (temp.length() == result.length() && temp < result)) {

                    result = temp;
                }
            }
        }

        return result;
    }
};