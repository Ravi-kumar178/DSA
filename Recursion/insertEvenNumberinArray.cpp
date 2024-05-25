#include<iostream>
#include<vector>
using namespace std;

void evenNumber(int arr[],int size, int index, vector<int>& ans){
    if(index>=size) return;
    if(arr[index]%2 == 0) ans.push_back(arr[index]);
    evenNumber(arr,size,++index,ans);
}

int main(){
    int arr[] = {1,2,3,-4,5};
    int size = 5;
    int index = 0;
    vector<int>ans;
    evenNumber(arr,size,index,ans);
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}