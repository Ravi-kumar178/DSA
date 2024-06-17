//full pyramid

#include<iostream>
using namespace std;

int main(){
    int rowCount;
    cin>>rowCount;
    cout<<"The row number is: "<<rowCount<<endl;
    
    for(int row = 0; row < rowCount; row++){
        //space print
        for(int j = 0; j < rowCount-row-1; j++){
            cout<<" ";
        }
        //star print
        for(int j = 0; j < row+1; j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}