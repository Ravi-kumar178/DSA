//full pyramid

#include<iostream>
using namespace std;

int main(){
    int rowCount;
    cin>>rowCount;
    cout<<"The row number is: "<<rowCount<<endl;
    
    for(int row = 0; row < rowCount; row++){
        //space 
        for(int col = 0; col < row; col++){
            cout<<" ";
        }
        //start space
        for(int col = 0; col < rowCount-row; col++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}