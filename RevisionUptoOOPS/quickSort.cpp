#include<iostream>
#include<vector>
using namespace std;

void quickSort(int arr[], int s, int e){
    int pivot = e;
    int i = s-1;
    int j = s;
    
    //base case 
    if(s>=e)return;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            ++i;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    ++i;
    swap(arr[i],arr[pivot]);
    
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}

int main(){
    int arr[5] = {5,4,3,2,1};
    int size = 5;
    int s = 0;
    int e = size-1;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl<<endl;
    quickSort(arr,s,e);
    for(int i : arr){
        cout<<i<<" ";
    }
}