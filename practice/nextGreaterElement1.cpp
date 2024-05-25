class Solution {
public:

    int Search(vector<int>& nums2, int target){
       for(int i = 0; i < nums2.size() ; i++){
         if(nums2[i] == target){
            return i;
            break;
         }
       }
       return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        vector<int>arr;
        while(i < nums1.size()){
            int target = nums1[i];
            int index = Search(nums2,target);
            cout<<"target: "<<target<<"index: "<<index<<endl;
            int ans = -1;
            for(int j = index+1; j < nums2.size();j++){
                if(nums2[j] > target){
                    ans = nums2[j];
                    break;
                }
            }
            arr.push_back(ans);
            i++;
        }
        return arr;
    }
};