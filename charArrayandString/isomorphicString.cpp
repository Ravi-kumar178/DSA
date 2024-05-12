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
        //convert string to mapped ones
        for(int i = 0; i < s.size();i++){
            char ch = s[i];
            s[i] = mapping[ch];
        }
    }

    bool isIsomorphic(string s, string t) {
        createMapping(t);
        cout<<"t: "<<t<<endl;
        createMapping(s);
        cout<<"s: "<<s<<endl;
        if(s == t){
            return true;
        }
        return false;
    }
};