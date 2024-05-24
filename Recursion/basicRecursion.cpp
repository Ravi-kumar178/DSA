#include<iostream>
using namespace std;

/* int solve(int n){
    if(n == 0) return 1;
    int ans = 2*solve(n-1);
    return ans;
} */

void printCount(int n){
  if(n == 0) return;
  cout<<n<<" ";
  printCount(n-1);
  cout<<n<<" ";
}

int main(){
 /*    int n = 5;
    int ans = solve(n);
    cout<<"2^n is: "<<ans<<endl; */
  int n;
  cin>>n;
  printCount(n);
  
    return 0;
}