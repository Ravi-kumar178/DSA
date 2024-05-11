class Solution {
public:
    bool isAnagram(string s, string t) {
        
       int mapping[260] = {0};
       for(char ch:s){
         mapping[ch]++;
       }

       for(char ch:t){
        mapping[ch]--;
       }

       for(int value:mapping){
         if(value != 0){
            return false;
         }
       }
       return true;

    }
};