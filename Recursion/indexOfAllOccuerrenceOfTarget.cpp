#include<iostream>
using namespace std;

void occurrence(int arr[],int size,int index, int target){
    if(index >= size) return;
    if(arr[index] == target) cout<<index<<" ";
    occurrence(arr,size,++index,target);
}

int main(){
    int arr[] = {1,2,1,1,3,4};
    int size = 5;
    int index = 0;
    int target = 1;
    occurrence(arr,size,index,target);
    return 0;
}