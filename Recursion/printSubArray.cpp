#include<iostream>
#include<vector>
using namespace std;

void printSubArray(vector<int>& nums, int start, int end){
    if(end == nums.size()) return;
    cout<<endl;
    
    for(int i = start; i <= end; i++){
        cout<<nums[i]<<" ";
    }
    printSubArray(nums,start,end+1);
}


int main(){
    vector<int>nums{1,2,3,4,5};
    int start = 0;
    while(start < nums.size()){
        int end = start;
        printSubArray(nums,start,end);
        cout<<endl;
        ++start;
    }
    return 0;
}