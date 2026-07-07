class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        stack<int>st;
        
        int pos = s.size()/2;
        
        while(pos){
            int top = s.top();
            st.push(top);
            s.pop();
            pos--;
        }
        //mid ele at top
        s.pop();
        
        while(!s.empty()){
            int top = s.top();
            st.push(top);
            s.pop();
        }
        
        while(!st.empty()){
            int top = st.top();
            s.push(top);
            st.pop();
        }
        return;
    }
};