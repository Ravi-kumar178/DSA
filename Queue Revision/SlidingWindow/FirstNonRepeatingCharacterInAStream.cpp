class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char>q;
        string ans;
        int freq[26] = {0};
        
        for(char ch: s){
            freq[ch-'a']++;
            q.push(ch);
            
            while(!q.empty()){
                if(freq[q.front()-'a'] > 1){
                    q.pop();
                }
                else{
                    ans.push_back(q.front());
                    break;
                }
            }
            
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
        return ans;
    }
};