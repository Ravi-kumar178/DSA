class Solution {
  public:
    void InsertAtBottom(stack<int>& st,int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }
        //1 case
        int num = st.top();
        st.pop();
        //recursive call
        InsertAtBottom(st,temp);
        //backtrack
        st.push(num);
    }
    void solve(stack<int>& st){
        if(st.empty()) return;
        //1 case
        int temp = st.top();
        st.pop();
        //recursive call
        solve(st);
        //insert at bottom
        InsertAtBottom(st,temp);
    }
    void reverseStack(stack<int> &st) {
        // code here
        solve(st);
    }
};