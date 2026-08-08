class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;

        string ans = "";
        int n = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                n = n * 10 + (ch - '0');
            }
            else if (ch == '[') {
                num.push(n);
                str.push(ans);

                n = 0;
                ans = "";
            }

            else if (ch != ']') {
                ans += ch;
            }
            else {
                int times = num.top();
                num.pop();

                string previous = str.top();
                str.pop();

                string temp = "";

                for (int i = 0; i < times; i++) {
                    temp += ans;
                }

                ans = previous + temp;
            }
        }

        return ans;
    }
};