class Solution {
public:
    vector<int>nextSmallerIndex(vector<int>heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());

        for(int i = heights.size()-1; i >= 0; i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerIndex(vector<int>heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());

        for(int i = 0; i < heights.size(); i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmallerIndex(heights);
        vector<int>prev = prevSmallerIndex(heights);
        for(int i = 0; i < next.size(); i++){
            cout<<next[i]<<" ";
        }
        //in next if there is -1, then replace it with heights.size
        for(int i = 0; i < heights.size(); i++){
            if(next[i] == -1){
                next[i] = heights.size();
            }
        }
        //find width , length is there then find max area
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            int width = next[i]-prev[i]-1;
            int currArea = width*heights[i];
            maxArea = max(maxArea,currArea);
        }
        //return max area
        return maxArea;
    }
};