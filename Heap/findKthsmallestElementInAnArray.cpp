#include<iostream>
#include<queue>
using namespace std;

int kthSmallestElement(int arr[],int size, int k){
    priority_queue<int>pq;

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < size; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int kthLargestElement(int arr[], int size, int k){
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i < size; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main(){
    int arr[] = {10,3,2,50,14,17,9};
    int size = 6;
    int k = 3;

    int ans = kthSmallestElement(arr,size,k);
    cout<<"Kth smallest element is: "<<ans<<endl;

    int secondAns = kthLargestElement(arr,size,k);

    cout<<"Kth largest Element is: "<<secondAns<<endl;

    return 0;
}