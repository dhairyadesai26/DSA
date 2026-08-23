class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int Lsum = 0, Rsum = 0;
        int Lcount = 0, Rcount = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                Lcount++;
            else
                Lsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                Rcount++;
            else
                Rsum += num[i] - '0';
        }

        int qDiff = Lcount - Rcount;
        int sumDiff = Lsum - Rsum;

        if (qDiff == 0)
            return sumDiff != 0;

        if (abs(qDiff) % 2 == 1)
            return true;

        if (qDiff > 0)
            return sumDiff + 9 * (qDiff / 2) != 0;

        return sumDiff - 9 * ((-qDiff) / 2) != 0;
    }
};