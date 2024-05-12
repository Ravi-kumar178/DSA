class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i = 0; i < strs.size();i++){
            string currString = strs[i];

            if(i == 0){
                for(int a = 0; a < currString.size(); a++){
                    ans.push_back(currString[a]);
                }
            }
            else{
              if(ans.size() > currString.size()){
                for(int j = 0; j < (ans.size()-currString.size()); j++){
                    ans.pop_back();
                }
              }

           
                int k = 0;
                while(k < ans.size()){
                    if(ans[k] == currString[k]){
                        k++;
                    }
                    else{
                        for(int i = 0; i < ans.length()-k;i++){
                            ans.pop_back();
                        }
                    }
                }
           }
           
        }
        return ans;
    }
};