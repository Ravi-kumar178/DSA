class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        //init
        queue<char>q;
        string ans = "";
        unordered_map<char,int>mp;
        
        //logic
        //iterate over each char, map with count, push in queue,
        //pop in a queue and prepare ans
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch]++;
            q.push(ch);
            
            while(!q.empty()){
                char frontChar = q.front();
                if(mp[frontChar] > 1){
                    q.pop();
                }
                else{
                    ans += frontChar;
                    break;
                }
            }
            
            if(q.empty()){
                ans += '#';
            }
        }
        return ans;
    }
};