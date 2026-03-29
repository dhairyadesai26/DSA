class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        //check for pre-match
        if(s1==s2){
            return true;
        }
        // check that if s1 can be made equal to s2
        for(int i=0;i<s1.size()-1;i++){
            for(int j=i+1;j<s1.size();j++){
                 if(j-i==2){
                    swap(s1[i],s1[j]);
                 }
                 if(s1==s2) return true;
            }
        }
            // check that if s2 can be made equal to s1
          for(int i=0;i<s2.size()-1;i++){
            for(int j=i+1;j<s2.size();j++){
                 if(j-i==2){
                    swap(s2[i],s2[j]);
                 }
                 if(s1==s2) return true;
            }
        }
        // cannot be made equal
        return false;
    }
};