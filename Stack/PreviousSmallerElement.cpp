class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>st;
        st.push(-1);
        vector<int>ans(arr.size());
        
        for(int i = 0; i < arr.size(); i++){
            while(st.top() >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};