class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int a = (5*arr.size())/100;
        sort(arr.begin(),arr.end());
        for(int i = 0; i < a; i++){
            arr.pop_back();
        }
        reverse(arr.begin(),arr.end());
        for(int i = 0; i < a; i++){
            arr.pop_back();
        }
        for(int i = 0; i < arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        double sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
        }
        return sum/arr.size();
    }
};