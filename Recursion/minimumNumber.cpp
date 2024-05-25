#include<iostream>
#include<limits.h>
using namespace std;

int minimum(int arr[],int size,int index, int mini){
    if(index >= size) return mini;
    if(arr[index] < mini) mini = arr[index];
    return minimum(arr,size,index+1,mini);
}

int main(){
    int arr[] = {1,2,3,-4,5};
    int size = 5;
    int index = 0;
    int mini = INT_MAX;
    int num = minimum(arr,size,index,mini);
    cout<<"Minimum number: "<<num<<endl;
    return 0;
}