#include<iostream>
using namespace std;

bool sorted(int arr[], int size, int index){
    if(index >= size) return true;
    if(arr[index-1] >= arr[index]) return false;
    bool ans = sorted(arr,size,++index);
    return ans;
}

int main(){
    int arr[] = {10,20,30,50,60,70};
    int size = 6;
    int index = 1;
    bool ans = sorted(arr,size,index);
    if(ans) cout<<"Array is sorted";
    else cout<<"Array is not sorted";
    return 0;
}