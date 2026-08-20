class Solution {
  public:
    bool sumEqualsSum(vector<int> &arr) {
        // code here.
        unordered_map<int, pair<int, int>> mp;

        for (int i = 0; i < arr.size() - 1; i++) {
            int num = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                int sum = arr[i] + arr[j];
                pair<int, int> p = {i, j};

                if (mp.find(sum) != mp.end()) {
                    return true;
                } else {
                    mp[sum] = p;
                }
            }
        }
        return false;
    }
};