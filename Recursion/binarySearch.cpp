#include<iostream>
using namespace std;

bool search(int arr[], int start, int end, int mid, int target){
    if(start > end) return false;
    if(arr[mid] == target) return true;
    else if(target > arr[mid]) start = mid+1;
    else end = mid-1;
    mid = start+(end-start)/2;
    return search(arr,start,end,mid,target);
}

int main(){
    int arr[] = {10,20,30,40,50};
    int start = 0;
    int end = 4;
    int target = 40;
    int mid = start + (end-start)/2;
    bool found = search(arr,start,end,mid,target);
    if(found) cout<<"Target found";
    else cout<<"Target not found";
    return 0;
}