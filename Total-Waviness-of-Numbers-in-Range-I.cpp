1class Solution {
2public: 
3     int solve(int a){ 
4        string s=to_string(a);
5        int n=s.size();
6        if(n<3){
7            return 0;
8        }
9        int total=0;
10        for(int i=1;i<=n-2;i++){
11           if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])){ 
12            total++;
13             }
14        }
15        return total;
16     }
17    int totalWaviness(int num1, int num2) {
18        int sum=0;
19        for(int i=num1;i<=num2;i++){
20            sum+=solve(i);
21        }
22        return sum;
23    }
24};