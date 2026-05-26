1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int count=0;
5        int n=word.length();
6        unordered_map<char,bool> mp;
7        
8        for(int i=0;i<n;i++){
9            for(int j=0;j<n;j++){
10                if(toupper(word[i])==word[j] && !mp[word[i]] && !(word[i]>='A' && word[i]<='Z')){
11                    count++;
12                    mp[word[i]]=true;
13                }
14            }
15             
16        }
17        return count;
18
19    }
20};