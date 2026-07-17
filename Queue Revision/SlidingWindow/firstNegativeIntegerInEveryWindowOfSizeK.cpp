class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        queue<int>q;
        
        //process first window
        for(int i = 0; i < k; i++){
            if(arr[i] < 0) q.push(i);
        }
        
        //storing the ans of last window and move to next window
        for(int i = k; i < arr.size(); i++){
            //store ans
            if(q.empty()) ans.push_back(0);
            else ans.push_back(arr[q.front()]);
            
            if(!q.empty() && i-q.front() >= k) q.pop();
            
            if(arr[i] < 0) q.push(i);
        }
        
        //store the ans of last window
         if(q.empty()) ans.push_back(0);
         else ans.push_back(arr[q.front()]);
        
        return ans;
    }
};