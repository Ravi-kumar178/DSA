class Compare {
    public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) {
            return a.first < b.first; 
        }
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;

        for(string s: words){
            mp[s]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;
        vector<string>ans;

        for(auto ele: mp){
            pq.push({ele.second,ele.first});
        }

        while((k > 0) && !pq.empty()){
            auto top = pq.top(); pq.pop();
            ans.push_back(top.second);
            k--;
        }
        return ans;
    }
};