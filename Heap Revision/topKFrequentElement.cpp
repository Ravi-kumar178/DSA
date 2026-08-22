class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freqMap;
        for(int num: nums){
            freqMap[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        for(auto entry: freqMap){
            if(minHeap.size() < k){
                minHeap.push({entry.second,entry.first});
            }
            else{
                if(minHeap.top().first < entry.second){
                    minHeap.pop();
                    minHeap.push({entry.second,entry.first});
                }
            }
        }

        vector<int>ans;
        while(!minHeap.empty()){
            auto [freq, num] = minHeap.top(); minHeap.pop();
            ans.push_back(num);
        }
        return ans;
    }
};