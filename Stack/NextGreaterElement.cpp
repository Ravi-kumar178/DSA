class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        //initialization
        stack<int>st;
        vector<int>ans(arr.size(),-1);
        
        for(int i = arr.size()-1; i >= 0; i--){
            if(st.empty()){
                st.push(arr[i]);
            }
            else if(st.top() > arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && st.top() <= arr[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                st.push(arr[i]);
            }
        }
        return ans;
    }
};