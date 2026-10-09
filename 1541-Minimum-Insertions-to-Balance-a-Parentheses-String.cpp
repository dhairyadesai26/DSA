class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int balance=0;
        int add=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                balance=balance+2;
                if(balance %2 !=0){
                    add++;
                    balance--;
                }
            }
            else{
                balance--;
                if(balance<0){
                    add++;
                    balance=1;
                }


            }

        }
        return add+balance;
       

    

        
    }
};