class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '['){
                //opening bracket
                st.push(ch);
            }
            else{
                //closing bracket
                if(st.empty()) return false;

                if(!st.empty() && (
                  (st.top()=='(' && ch == ')') ||
                  (st.top()=='[' && ch == ']') ||
                  (st.top()=='{' && ch == '}')
                )){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0? true:false;
    }
};