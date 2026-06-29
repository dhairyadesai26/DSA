1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int n=word.length();
5        int count=0;
6        vector<string> substrings;
7        for(int i=0;i<n;i++){
8            for(int j=i;j<n;j++){
9                substrings.push_back(word.substr(i, j - i + 1));
10
11            }
12
13        }
14         for(string s:patterns){
15           auto it=find(substrings.begin(),substrings.end(),s);
16           if(it!=substrings.end()){
17            count++;
18           }
19         }
20        return count;
21    }
22};