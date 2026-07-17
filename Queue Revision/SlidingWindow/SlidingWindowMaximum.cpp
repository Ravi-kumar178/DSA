class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        //process first window
        for(int i = 0; i < k; i++){
            int ele = nums[i];
            if(!dq.empty() && ele > nums[dq.front()]) dq.pop_front();
            while(!dq.empty() && ele > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        //store ans and process the remaining window
        for(int i = k; i < nums.size(); i++){
            int ele = nums[i];

            //store ans of prev window
            ans.push_back(nums[dq.front()]);

            //check range
            if(!dq.empty() && i-dq.front() >= k) dq.pop_front();

            if(!dq.empty() && ele > nums[dq.front()]) dq.pop_front();
            while(!dq.empty() && ele > nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
        }

        //store ans of last window
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};