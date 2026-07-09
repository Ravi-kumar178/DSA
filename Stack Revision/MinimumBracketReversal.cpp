class Solution {
public:
    int countReversals(string str) {
        // Logic to be implemented by user
        if(str.size()&1) return -1;

        //at first remove the valid part of bracket
        stack<int>st;

        for(char ch: str){
            if(ch == '{') st.push(ch);
            else{
                if(!st.empty() && st.top() == '{') st.pop();
                else st.push(ch);
            }
        }

        int operation = 0;

        while(!st.empty()){
            char A = st.top(); st.pop();
            char B = st.top(); st.pop();

            if((A == '{' && B == '{') || (A == '}' && B == '}')) operation += 1;
            else operation += 2;
        }
        return operation;
    }
};