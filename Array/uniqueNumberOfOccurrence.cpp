class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int>ans;
        int count = 0;
        int num = arr[0];
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == num){
                count++;
            }
            else{
                ans.push_back(count);
                num = arr[i];
                count = 1;
            }
        }
        ans.push_back(count);
        //sort the ans array
        sort(ans.begin(),ans.end());

        //couting ans
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }

        if(ans.size() == 1){
            return true;
        }

        for(int i = 1; i < ans.size(); i++){
            if((i-1 >= 0) && (ans[i] == ans[i-1])){
                return false;
            }
        }
        return true;
    }
};