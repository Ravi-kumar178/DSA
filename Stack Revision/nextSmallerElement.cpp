class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int>s;
        s.push(-1);
        vector<int>ans(arr.size());
        
        for(int i = arr.size()-1; i >= 0; i--){
            int curr = arr[i];
            
            while(curr <= s.top()) s.pop();
            
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    }
};