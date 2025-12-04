class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st;
        
        //fill st untill !q.empty()
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            st.push(temp);
        }
        
        //fill q untill !st.empty()
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            q.push(temp);
        }
        
    }
};