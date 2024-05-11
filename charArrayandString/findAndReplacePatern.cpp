class Solution {
public:

    void createMapping(string &s){
        char mapping[260] = {0};
        char start = 'a';

        for(auto ch:s){
            if(mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }
        //convert string to mapped string
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            s[i] = mapping[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        createMapping(pattern);
        cout<<"Pattern: "<<pattern<<endl;
        vector<string>ans;
        for(string s:words){
            string tempString = s;
            createMapping(tempString);
            if(tempString == pattern){
              ans.push_back(s);
            }
        }
        return ans;
    }
};