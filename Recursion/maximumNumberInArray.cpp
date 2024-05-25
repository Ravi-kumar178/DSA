#include<iostream>
#include<limits.h>
using namespace std;

int maximum(int arr[],int size, int index, int maxi){
    if(index >= size) return maxi;
    if(arr[index]>maxi) maxi = arr[index];
    return maximum(arr,size,++index,maxi);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int index = 0;
    int maxi = INT_MIN;
    int num = maximum(arr,size,index,maxi);
    cout<<"Maximum number: "<<num<<endl;
    return 0;
}