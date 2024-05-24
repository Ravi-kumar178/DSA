#include<iostream>
using namespace std;

int fact(int n){
    if(n == 0) return 1;
    int ans = n*fact(n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans = fact(n);
    cout<<"Factorial is: "<<ans<<endl;
    return 0;
}