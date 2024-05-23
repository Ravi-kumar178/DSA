class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            for(int j = 0; j < str.size(); j++){
                if(str[j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};