
#include<iostream>
#include<vector>
using namespace std;

  int binarySearch(vector<int>&nums , int s , int e, int target){
        int mid = s+(e-s)/2;

        while(s <= e){
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }

int main(){
     vector<int>nums = {1};
     int s = 0;
     int target = 0;
        int e = nums.size()-1;
        int n = nums.size();
        int mid = s+(e-s)/2;
        int pivot;
        int ans;
        
        
        if(n-1 == 0){
            pivot = 0;
        }
        else{
            while(s <= e){
                if((mid+1 < n) && (nums[mid] > nums[mid+1])){
                    cout<<"mid: "<<mid<<endl;
                   pivot = mid;
                   break;
                }
                else if((mid-1 >= 0) && (nums[mid] < nums[mid-1])){
                    pivot = mid-1;
                    break;
                }
                else if((nums[mid] < nums[s])){
                    e = mid-1;
                }
                else if(nums[mid] > nums[s]){
                    s = mid+1;
                }
                mid = s + (e-s)/2;
            }
        }    
        cout<<"pivot: "<<pivot<<endl;
        
       if(target >= nums[0] && target <= nums[pivot]){
            ans = binarySearch(nums,0,pivot,target);
        }
       else if (target >= nums[pivot+1] && target <= nums[n-1]){
            ans = binarySearch(nums,pivot+1,n-1,target);
        }
        cout<<"return ans: "<<ans<<endl;
        
}