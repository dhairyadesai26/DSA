1class Solution {
2public:
3 int n;
4 vector<int> t;
5
6int solve(vector<int>& arr,int i,int d){
7    if(t[i]!=-1){
8        return t[i];
9    }
10    int result=1;
11
12    for(int j=i-1;j>=max(0,i-d);j--){
13        if(arr[j]>=arr[i]) break;
14        result=max(result,1+solve(arr,j,d));
15
16    }
17    for(int j=i+1;j<=min(n-1,i+d);j++){
18        if(arr[j]>=arr[i]) break;
19        result=max(result,1+solve(arr,j,d));
20        
21    }
22    return t[i]=result;
23}
24    int maxJumps(vector<int>& arr, int d) {
25        n=arr.size();
26        t.resize(n+1,-1);
27        int result=1;
28        for(int i=0;i<n;i++){
29            result=max(result,solve(arr,i,d));
30        
31        }
32        return result;
33
34    }
35};