class Solution {
public:
    bool areOccurrencesEqual(string s) {
        char mapping[26] = {0};
        for(char ch: s){
            mapping[ch-'a']++;
        }
      

        int a = mapping[s[0]-'a'];

        for(int i = 0; i < 26; i++){
            if((mapping[i]!=0)&&(mapping[i]!= a)) return false;
        }
        return true;


    }
};