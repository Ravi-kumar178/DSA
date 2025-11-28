class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        //if s is odd then it can't be balanced expression
        if(s.size()&1) return -1;
        stack<char>st;
        for(char ch: s){
            if(ch == '{'){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        //valid paranthesis is removed , now count the operation for reversal
        int countOfOperation = 0;
        while(!st.empty()){
            char A = st.top(); st.pop();
            char B = st.top(); st.pop();
            
            if(A == B) countOfOperation += 1;
            else 
                countOfOperation += 2;
        }
        return countOfOperation;
    }
};