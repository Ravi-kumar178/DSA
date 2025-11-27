class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch: s){
            if(st.empty()){
                st.push(ch);
            }
            else if(ch == st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        stack<char>newSt;
        while(!st.empty()){
            newSt.push(st.top());
            st.pop();
        }
        string ans;
        while(!newSt.empty()){
            ans.push_back(newSt.top());
            newSt.pop();
        }
        return ans;
    }
};