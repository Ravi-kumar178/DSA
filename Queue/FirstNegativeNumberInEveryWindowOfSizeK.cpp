class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int>q;
        vector<int>ans;
        
        //process first window
        for(int i = 0; i < k; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        //process for remaining window
        for(int i = k; i < arr.size(); i++){
            //store ans
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[q.front()]);
            }
            //removal from queue
            if(!q.empty() && i-q.front() >= k){
                q.pop();
            }
            //addition
            if(arr[i] < 0){
                q.push(i);
            }
        }
        //push the ans of last window
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};