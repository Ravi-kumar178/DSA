class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq; vector<int>ans;

        //process first window
        for(int i = 0; i < k; i++){
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //process remaining window
        for(int i = k; i < nums.size(); i++){
            //store ans
            ans.push_back(nums[dq.front()]);
            //removal -> first by index then by smaller dq element
            if(i-dq.front() >= k) {
                dq.pop_front();
            }
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            //addition
            dq.push_back(i);
        }
        //store ans of last window
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};