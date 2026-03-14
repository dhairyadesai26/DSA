class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> freq1;
         unordered_map<char,int> freq2;
         vector<int> ans1;
         vector<int> ans2;
         for(char c:word1){
            freq1[c]++;
         }
         for(char c:word2){
            freq2[c]++;
         }
          for(char c:word1){
            ans1.push_back(freq1[c]);
         }
         for(char c:word2){
           ans2.push_back(freq2[c]);
         }
         sort(ans1.begin(),ans1.end());
          sort(ans2.begin(),ans2.end());
          if(ans1!=ans2){
            return false;
          }

         for(char c:word1){
           if( (word2.find(c)==string::npos)){
            return false;
                
           }

         }
            for(char c:word2){
           if( (word1.find(c)==string::npos)){
            return false;
                
           }

         }

         if(word1.size()!=word2.size()){
            return false;
           }
          return true;

    }
};