1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        unordered_map<char,int> fq;
5        int count=0;
6        int m=text.length();
7         for(int i=0;i<m;i++){
8            fq[text[i]]++;
9           
10
11         }
12
13      while (fq['b'] != 0) {
14    if (fq['b'] >= 1 && fq['a'] >= 1 &&
15        fq['l'] >= 2 && fq['o'] >= 2 &&
16        fq['n'] >= 1) {
17
18        count++;
19
20        fq['b']--;
21        fq['a']--;
22        fq['l'] -= 2;
23        fq['o'] -= 2;
24        fq['n']--;
25    }
26    else {
27        break;
28    }
29}
30        return count;
31
32    }
33};