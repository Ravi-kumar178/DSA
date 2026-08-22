#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int index;

    Heap(int capacity){
        this->size = capacity;
        arr = new int[size];
        this->index = 0;
    }

    void push(int val){
        if(index == size-1){
            cout<<"Heap overflow"<<endl;
            return;
        }

        index++;
        arr[index] = val;

        int childIndex = index;
        while(childIndex > 1){
            int parentIndex = childIndex/2;
            if(arr[childIndex] > arr[parentIndex]){
                swap(arr[childIndex],arr[parentIndex]);
            }
            else{
                break;
            }
            childIndex /= 2;
        }
        return;
    };

    void heapify(int* arr, int capacity, int currentIndex){
        int i = currentIndex;
        int leftChild = 2*i;
        int rightChild = 2*i+1;

        int largestIndex = i;

        if((leftChild <= capacity) && (arr[leftChild] > arr[i])){
            largestIndex = leftChild;
        }
        if((rightChild <= capacity) && (arr[rightChild] > arr[largestIndex])){
            largestIndex = rightChild;
        }

        if(largestIndex != i){
            swap(arr[currentIndex],arr[largestIndex]);
            i = largestIndex;
            heapify(arr,capacity,largestIndex);
        }
        return;
    }

    void pop(){
        if(index == 0){
            cout<<"underflow"<<endl;
            return;
        }
        swap(arr[1],arr[index]);
        index--;
        heapify(arr,index,1);
        return;
    }

    int top(){
        return index == 0 ? -1 : arr[1];
    }
};



int main(){
    Heap hp(6);
    hp.push(1);
    cout<<hp.top()<<endl;
    hp.push(2);
    cout<<hp.top()<<endl;
    hp.push(3);
    cout<<hp.top()<<endl;
    hp.push(4);
    cout<<hp.top()<<endl;
    hp.push(5);
    cout<<hp.top()<<endl;
 // hp.push(6); Heap overflow
    hp.pop();
    cout<<hp.top()<<endl;
}