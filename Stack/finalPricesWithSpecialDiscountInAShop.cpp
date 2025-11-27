class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //next smaller element arr
        stack<int>st;
        st.push(-1);
        vector<int>ans(prices.size());

        for(int i = prices.size()-1; i >= 0; i--){
            while(st.top() > prices[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(prices[i]);
        }

        //iterate over ans arr
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == -1){
                ans[i] = prices[i];
            }
            else{
                ans[i] = prices[i]-ans[i];
            }
        }
        return ans;
    }
};