#include<iostream>
#include<vector>
using namespace std;

void mergeArray(int arr[],int s, int e){
    //divide
    int mid = s+(e-s)/2;
    vector<int>leftArray;
    vector<int>rightArray;
    
    //copy the element from arr to leftArray and rightArray
    int leftArrayLength = mid-s+1;
    int rightArrayLength = e-mid;
    int mainArrayIndex = s;
    //left array copy
    for(int i = 0; i < leftArrayLength; i++){
        leftArray.push_back(arr[mainArrayIndex++]);
    }
    mainArrayIndex = mid+1;
    //right array copy
    for(int i = 0; i < rightArrayLength; i++){
        rightArray.push_back(arr[mainArrayIndex++]);
    }
    
    int i = 0;
    int j = 0;
    mainArrayIndex = s;
    while((i < leftArrayLength)&&(j < rightArrayLength)){
        if(leftArray[i] < rightArray[j]){
            arr[mainArrayIndex++] = leftArray[i++];
        }
        else{
            arr[mainArrayIndex++] = rightArray[j++];
        }
    }
    
    for(int k = i ; k < leftArrayLength; k++){
        arr[mainArrayIndex++] = leftArray[k];
    }
    for(int k = j; k < rightArrayLength; k++){
        arr[mainArrayIndex++] = rightArray[k];
    }
}

void mergeSort(int arr[], int s, int e){
    //base case
    if(s >= e) return;
    
    //divide
    int mid = s+(e-s)/2;
    //left
    mergeSort(arr,s,mid);
    //right
    mergeSort(arr,mid+1,e);
    mergeArray(arr,s,e);
}

int main(){
    int arr[] = {5,4,3,2,1};
    int size = 5;
    int start = 0;
    int end = size-1;
    mergeSort(arr,start,end);
    cout<<"After Sorting"<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
