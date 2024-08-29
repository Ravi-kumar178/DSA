#include<iostream>
#include<vector>
using namespace std;

void mergeArray(int arr[], int s, int e){
    int mid = s+(e-s)/2;
    vector<int>leftArray;
    vector<int>rightArray;
    int leftArrayLength = mid-s+1;
    int rightArrayLength = e-mid;
    int mainArrayIndex = s;
    
    //left array 
    for(int i = 0; i < leftArrayLength; i++){
        leftArray.push_back(arr[mainArrayIndex++]);
    }
    
    //right array 
    for(int i = 0; i < rightArrayLength ; i++){
        rightArray.push_back(arr[mainArrayIndex++]);
    }
    
    //two pointer
    int i = 0, j = 0;
    mainArrayIndex = s;
    while((i < leftArrayLength)&&(j < rightArrayLength)){
        if(leftArray[i] < rightArray[j]){
            arr[mainArrayIndex++] = leftArray[i++];
        }
        else{
            arr[mainArrayIndex++] = rightArray[j++];
        }
    }
    for(int k = i; k < leftArrayLength ; k++){
        arr[mainArrayIndex++] = leftArray[k];
    }
    for(int k = j; k < rightArrayLength ; k++){
        arr[mainArrayIndex++] = rightArray[k];
    }
}

void mergeSortArray(int arr[], int s, int e){
    if(s >= e) return;
    int mid = s + (e-s)/2;
    mergeSortArray(arr,s,mid);
    mergeSortArray(arr,mid+1,e);
    mergeArray(arr,s,e);
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
    mergeSortArray(arr,s,e);
    for(int i : arr){
        cout<<i<<" ";
    }
}