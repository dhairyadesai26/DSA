class Solution {
public:
    bool checkOnesSegment(string s) {
        if(!s.contains("01")){
            return true;
        }
        return false;
    }
};