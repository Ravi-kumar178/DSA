class Solution {
public:
    vector<int>nextGreaterElementIndex(vector<int> temperatures){
        stack<int>st;
        vector<int>ans(temperatures.size());

        //logic
        for(int i = temperatures.size()-1; i >= 0; i--){
            if(st.empty()){
                ans[i] = 0;
                st.push(i);
            }
            else if(temperatures[st.top()] > temperatures[i]){
                ans[i] = st.top();
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                else{
                    ans[i] = 0;
                }
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>temp = nextGreaterElementIndex(temperatures);
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != 0){
                temp[i] -= i;
            }
        }
        return temp;
    }
};