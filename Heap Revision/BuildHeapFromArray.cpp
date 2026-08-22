#include<iostream>
using namespace std;

void heapify(int arr[], int size, int currentIndex){
    int i = currentIndex;
    int leftChild = 2*i;
    int rightChild = 2*i+1;

    int largestIndex = i;
    if((leftChild <= size) && (arr[leftChild] > arr[largestIndex])){
        largestIndex = leftChild;
    }
    if((rightChild <= size) && (arr[rightChild] > arr[largestIndex])){
        largestIndex = rightChild;
    }

    if(largestIndex == currentIndex) return;

    swap(arr[largestIndex],arr[currentIndex]);
    heapify(arr,size,largestIndex);

    return;
}

void buildHeap(int arr[], int size){
    for(int i = size/2; i >= 1; i--){
        heapify(arr,size,i);
    }
    return;
}

int main(){
    // int arr[] = {-1,10,20,30,40,50,60};
    int arr[] = {-1, 45, 12, 89, 3, 22, 100};
    buildHeap(arr,6);
    for(auto num: arr){
        cout<<num<<" ";
    }
    return 0;
}