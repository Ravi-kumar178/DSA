
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,5,10,20,40,80};
    int brr[] = {6,7,20,80,100};
    int crr[] = {3,4,15,20,30,70,80,120};
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while((i < 6) && (j < 5) && (k < 8)){
        
        if(arr[i] == brr[j] && brr[j] == crr[k]){
            cout<<arr[i]<<" ";
            i++;
            j++;
            k++;
        }
        else if(arr[i] < brr[j]){
            i++;
        }
        else if(crr[k] < brr[j]){
            k++;
        }
        else{
            j++;
        }
    }
    return 0;
}
