class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int currZ=0;
        int oneCnt=0;
        int maxOnes=0;
        int prevZ=0;
        int zeroS=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                currZ++;
            }
            else{
            oneCnt++;
            maxOnes=max(maxOnes,prevZ+currZ);
            if(currZ!=0){
                prevZ=currZ;
                zeroS++;

            }
            currZ=0;
            }


        }
        if(currZ!=0) zeroS++;
        maxOnes=max(maxOnes,prevZ+currZ);
        return oneCnt+(zeroS>1?maxOnes:0);
    }
};