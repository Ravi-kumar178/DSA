class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>arr;
        int ans = 0;
        int i = 0;
        while(i < n){
            for(int j = 0; j < m; j++){
                if(nums1[i] == nums2[j]){
                    ans++;
                    break;
                }
            }
            i++;
        }
        arr.push_back(ans);
        ans = 0;
        i = 0;
        while(i < m){
            for(int j = 0; j < n; j++){
                if(nums2[i] == nums1[j]){
                    ans++;
                    break;
                }
            }
            i++;
        }
        arr.push_back(ans);
        return arr;
    }
};