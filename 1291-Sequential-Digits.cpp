class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int len=2;len<=9;len++){
            for(int s=1;s+len-1<=9;s++){
                int num=0;
                for(int d=s;d<s+len;d++){
                    num=num*10+d;
                }
                if(num>=low && num<=high){
                    ans.push_back(num);
                }

            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};