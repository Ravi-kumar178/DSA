class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int j = arr.size()-1;
        while(j-i >= k){
            if(x-arr[i] >arr[j]-x){
                i++;
            }
            else{
                j--;
            }
        }
        vector<int>ans;
        for(int a = i; a <= j; a++){
            ans.push_back(arr[a]);
        }
        return ans;
    }
};