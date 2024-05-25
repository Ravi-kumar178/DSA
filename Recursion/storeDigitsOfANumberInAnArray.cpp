#include<iostream>
#include<vector>
using namespace std;

void storeDigits(int num,vector<int>& ans){
    if(num <= 0) return;
    int digit = num%10;
    //reverse array
    ans.push_back(digit);
    storeDigits(num/10,ans);
    
    ans.push_back(digit);
}

int main(){
    int num = 4215;
    vector<int>ans;
    storeDigits(num,ans);
    
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}