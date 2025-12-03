class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int>st;
       vector<int>ans;

       for(int asteroid: asteroids){
        if(asteroid > 0){
            st.push(asteroid);
        }
        else{
            if(!st.empty() && st.top() > 0){
                while(!st.empty() && st.top() > 0 && abs(asteroid) > st.top()){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroid)){
                    st.pop();
                }
                else if(!st.empty() && st.top() > abs(asteroid)){
                    continue;
                }
                else{
                    st.push(asteroid);
                }
            }
            else{
                st.push(asteroid);
            }
        }
       }
       while(!st.empty()){
        ans.push_back(st.top()); st.pop();
       } 
       reverse(ans.begin(),ans.end());
       return ans;
    }
};