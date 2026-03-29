class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(s1==s2){
            return true;
        }
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                 if(j-i==2){
                    swap(s1[i],s1[j]);
                 }
                 if(s1==s2) return true;
            }
        }
          for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                 if(j-i==2){
                    swap(s2[i],s2[j]);
                 }
                 if(s1==s2) return true;
            }
        }
        return false;
    }
};