#include<iostream>
using namespace std;

void heapifyDown(int arr[], int capacity, int i){
    int currentIndex = i;
    int leftChild = 2*i, rightChild = 2*i+1;

    int largestIndex = i;
    if((leftChild < capacity) && (arr[leftChild] > arr[currentIndex])){
        largestIndex = leftChild;
    }
    if((rightChild < capacity) && (arr[rightChild] > arr[largestIndex])){
        largestIndex = rightChild;
    }

    if(largestIndex == currentIndex) return;

    swap(arr[largestIndex],arr[currentIndex]);
    heapifyDown(arr,capacity,largestIndex);

    return;
}

void buildHeap(int arr[], int capacity){
    for(int i = capacity/2; i >= 1; i--){
        heapifyDown(arr,capacity,i);
    }
}

void print(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int arr[], int capacity){
    int n = capacity;
    while(n > 1){
        swap(arr[1],arr[n-1]);
        n--;
        heapifyDown(arr,n,1);
    }
    return;
}

int main(){
    int arr[] = {-1,10,20,30,40,50,60};
    int capacity = 7;

    buildHeap(arr,capacity);
    print(arr,capacity);

    heapSort(arr,capacity);
    print(arr,capacity);
}