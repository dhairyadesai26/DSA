class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        unordered_map<char,int> fq;
        for(int i=0;i<n;i++){
              fq[moves[i]]++;
        }
        for(int i=0;i<n;i++){
            if(fq['L']!=fq['R'] || fq['U']!=fq['D']){
                return false;
            }
        }
        return true;
    }
};