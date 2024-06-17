//full pyramid

#include<iostream>
using namespace std;

int main(){
    int rowCount;
    cin>>rowCount;
    cout<<"The row number is: "<<rowCount<<endl;
    
    for(int row = 0; row < rowCount; row++){
        //space print
        for(int col = 0; col < rowCount-row-1 ; col++){
            cout<<" ";
        }
        cout<<"*";
        //space print
        for(int col = 0; col < 2*row-1; col++){
            cout<<" ";
        }
        if(row != 0){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}