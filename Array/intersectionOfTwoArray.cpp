class Solution {
public:

  /*   vector<int> removeDuplicate(vector<int> &arr){
        vector<int>ans;
        int i = 1;
        sort(arr.begin(),arr.end());
        ans.push_back(arr[i]);
        while( i < arr.size()){
            if(arr[i] != arr[i-1]){
                ans.push_back(arr[i]);
            }
            i++;
        }
        return ans;
    }
 */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int>ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while((i < nums1.size() && j < nums2.size())){
            if(nums1[i] == nums2[j]){
                if(ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};