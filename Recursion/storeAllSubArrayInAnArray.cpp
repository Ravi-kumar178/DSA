#include<iostream>
#include<vector>
using namespace std;

void printSubArray(vector<int>& nums, int start, int end,vector<int>& arr,vector<vector<int>>& ans){
    if(end == nums.size()) return;
    cout<<endl;
    
    for(int i = start; i <= end; i++){
        cout<<nums[i]<<" ";
        arr.push_back(nums[i]);
    }
    ans.push_back(arr);
    for(int i = 0; i < arr.size(); i++){
        arr.pop_back();
    }
    printSubArray(nums,start,end+1,arr,ans);
}


int main(){
    vector<int>nums{1,2,3,4,5};
    int start = 0;
    vector<int>arr{};
    vector<vector<int>>ans{};
    while(start < nums.size()){
        int end = start;
        printSubArray(nums,start,end,arr,ans);
        cout<<endl;
        ++start;
    }
    cout<<"ans ka size: "<<ans.size()<<endl;
    cout<<"Arr ka size: "<<arr.size()<<endl;
    return 0;
}