#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>nums = {20,10,30,50,40,70,60};
    int n = nums.size();
    int target = 70;
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s+(e-s)/2;
    while(s <= e){
        if(target == nums[mid]){
            ans = mid;
            break;
        }
        else if(target == nums[mid-1]){
            ans = mid-1;
            break;
        }
        else if(target == nums[mid+1]){
            ans = mid+1;
            break;
        }
        else if(target > nums[mid]){
            s = mid+2;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    cout<<"req index: "<<ans<<endl;
}