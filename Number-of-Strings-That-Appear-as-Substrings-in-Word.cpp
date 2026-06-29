1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int count=0;
5        for(string &s:patterns){
6            if(word.find(s)!=string::npos){
7                count++;
8            }
9        }
10        return count;
11    }
12};