#include<iostream>
using namespace std;

void heapify(int arr[], int capacity, int i){
    int currentIndex = i;
    int leftChild = 2*i;
    int rightChild = 2*i+1;

    int largestIndex = i;
    if(leftChild < capacity && arr[leftChild] > arr[largestIndex]){
        largestIndex = leftChild;
    }
    if(rightChild < capacity && arr[rightChild] > arr[largestIndex]){
        largestIndex = rightChild;
    }

    if(largestIndex == currentIndex) return;

    swap(arr[largestIndex],arr[currentIndex]);
    heapify(arr,capacity,largestIndex);

    return;
}

void buildHeap(int arr[], int capacity){
    for(int i = capacity/2; i >= 1; i--){
        heapify(arr,capacity,i);
    }
    return;
}

int main(){
    int arr[] = {-1,10,20,30,40,50,60};
    int capacity = 7;
    buildHeap(arr,capacity);

    for(int num: arr){
        cout<<num<<" ";
    }
    return 0;
}