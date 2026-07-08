class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>st;
        st.push(-1);
        
        vector<int>ans(arr.size());
        
        for(int i = 0; i < arr.size(); i++){
            int curr = arr[i];
            
            while(curr <= st.top()) st.pop();
            
            ans[i] = st.top();
            st.push(curr);
        }
        
        return ans;
    }
};