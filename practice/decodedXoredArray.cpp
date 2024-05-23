class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        int i = 0;
        while(i < encoded.size()){
            int digit = ans.back()^encoded[i];
            ans.push_back(digit);
            i++;
        }
        return ans;
    }
};