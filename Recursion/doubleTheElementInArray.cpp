#include<iostream>
using namespace std;

void doubleArray(int arr[], int size, int index){
    if(index>=size) return;
    arr[index] = 2*arr[index];
    doubleArray(arr,size,index+1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;
    doubleArray(arr,size,index);
    for(int num:arr){
        cout<<num<<" ";
    }
    return 0;
}