
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = 8;
    
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans = 0;
    
    while(s <= e && (s < 8)){
        int diff = arr[mid] - mid;
        if(diff == 1){
           
            ans = arr[mid];
        
            s = mid+1;
        }
        else if(diff ==2){
            e = mid-1;
        }
        mid = s +(e-s)/2;
    }
    
    cout<<"missing number: "<<ans+1<<endl;
    return 0;
    
}