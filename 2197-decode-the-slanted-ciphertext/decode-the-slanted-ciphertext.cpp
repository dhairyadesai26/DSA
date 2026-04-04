class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;

        vector<vector<char>> grid(rows, vector<char>(cols));

        // Step 1: Fill row-wise
        int k = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                grid[i][j] = encodedText[k++];
            }
        }

        // Step 2: Traverse diagonally (↘)
        string ans = "";

        for(int col = 0; col < cols; col++) {
            int i = 0, j = col;

            while(i < rows && j < cols) {
                ans += grid[i][j];
                i++;
                j++;
            }
        }

        // Step 3: Remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};