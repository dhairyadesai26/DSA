class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R'){
                R.push(i);
            }
            else{
                D.push(i);
            }
        }
        while(!R.empty() && !D.empty()){
            int r=R.front();
            R.pop();
            int d=D.front();
            D.pop();
            if(r<d){
                R.push(r+senate.length());
            }
            else{
                D.push(d+senate.length());
            }
        }
    if(R.empty()){
        return "Dire";
    }
    else 
        return "Radiant";

    }
};