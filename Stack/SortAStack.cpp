class Solution {
  public:
    void insertInASortedStack(stack<int> &st, int element){
        if(st.empty() || element > st.top()){
            st.push(element);
            return;
        }
        int temp = st.top();
        st.pop();
        
        insertInASortedStack(st,element);
        st.push(temp);
    }
    
    void sortSolve(stack<int>&st){
        if(st.empty()) return;
        int temp = st.top();
        st.pop();
        sortSolve(st);
        insertInASortedStack(st,temp);
    }
    
    void sortStack(stack<int> &st) {
        // code here
        sortSolve(st);
    }
};
