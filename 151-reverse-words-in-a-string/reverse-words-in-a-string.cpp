class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string result="";
        string p="";
        for(int i=n-1;i>=0;i--){

            if(s[i]==' '){
                if(!p.empty()){
                 result+= p +" ";
                 p="";
                }
}
else{
            p=s[i]+p;
}
        }
if(!p.empty()){
    result+=p;
}
// remove trailing spaces
while(!result.empty() && result.back() == ' ') {
    result.pop_back();
}

// remove leading spaces
while(!result.empty() && result.front() == ' ') {
    result.erase(result.begin());
}

             
   
        return result;
    }
};