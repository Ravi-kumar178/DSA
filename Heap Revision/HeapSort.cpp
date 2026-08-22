#include<iostream>
using namespace std;

void heapify(int arr[], int n, int currentIndex){
    int i = currentIndex;
    int leftChild = 2*i;
    int rightChild = 2*i+1;
    int largestIndex = i;

    if((leftChild <= n) && (arr[leftChild] > arr[largestIndex])){
        largestIndex = leftChild;
    }
    if((rightChild <= n) && (arr[rightChild] > arr[largestIndex])){
        largestIndex = rightChild;
    }

    if(largestIndex == i) return;

    swap(arr[largestIndex],arr[currentIndex]);
    heapify(arr,n,largestIndex);
    return;
}

void buildHeap(int arr[], int n){
    for(int i = n/2; i >= 1; i--){
        heapify(arr,n,i);
    }
    return;
}

void heapSort(int arr[],int n){
    while(n > 1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
    return;
}

int main(){
    int arr[] = {-1,60,50,40,30,20,10};
    buildHeap(arr,6);
    for(auto num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
    heapSort(arr,6);
    for(auto num:arr){
        cout<<num<<" ";
    }
    cout<<endl;
}