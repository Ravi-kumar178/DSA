//quick sort 
#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& arr, int s, int e){
    //base case
    if(s >= e) return;
    int i = s-1;
    int j = s;
    int pivot = e;
    while(j < pivot){
        if(arr[j]<arr[pivot]){
            ++i;
            swap(arr[i],arr[j]);
        }
        ++j;
    }
    ++i;
    swap(arr[i],arr[pivot]);
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}

int main(){
    vector<int>arr = {5,4,3,2,1,-1};
    int size = 6;
    int s = 0;
    int e = size-1;
    quickSort(arr,s,e);
    for(int num:arr){
        cout<<num<<" ";
    }
    return 0;
}