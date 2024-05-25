#include<iostream>
using namespace std;

void printReverseArray(int arr[],int size, int index){
    if(index >= size) return;
    printReverseArray(arr,size,index+1);
    cout<<arr[index]<<" ";
}

void printArray(int arr[],int size, int index){
    if(index >= size) return;
    cout<<arr[index]<<" ";
    printArray(arr,size,index+1);
   
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;
    printArray(arr,size,index);
    cout<<endl;
    printReverseArray(arr,size,index);
    return 0;
}