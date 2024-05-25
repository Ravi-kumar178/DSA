#include<iostream>
using namespace std;

bool search(int arr[], int size , int index , int target){
    if(index >= size) return false;
    if(arr[index] == target) return true;
    bool ans = search(arr,size,index+1,target);
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;
    int target = 4;
    bool found = search(arr,size,index,target);
    if(found) cout<<"Target is present";
    else cout<<"Target not present";
    return 0;
}