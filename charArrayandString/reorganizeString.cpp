class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        //hash all char in string s
        for(int i=0; i < s.size();i++){
            hash[s[i]-'a']++;
        }
        //most_frequent
        int most_frequent = INT_MIN;
        char most_frequent_character;

        for(int i = 0; i < 26; i++){
            if(hash[i] > most_frequent){
                most_frequent = hash[i];
                most_frequent_character = 'a'+i;
            }
        }

        int i = 0;
        //place most frequent character
        while(most_frequent > 0 && i < s.size()){
            s[i] = most_frequent_character;
            i = i+2;
            most_frequent--;
        }

        if(most_frequent > 0){
            return "";
        }
        hash[most_frequent_character-'a'] = 0;
        for(int j = 0; j < 26; j++){ 
           while(hash[j]>0){
                i = i >= s.size()?1:i;
                s[i] = 'a'+j;
                hash[j]--;
                i= i+2;
            }
        }
        return s;
    }
};