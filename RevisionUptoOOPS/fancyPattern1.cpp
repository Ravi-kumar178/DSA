//full pyramid

#include<iostream>
using namespace std;

int main(){
    int rowCount;
    cin>>rowCount;
    cout<<"The row number is: "<<rowCount<<endl;
   
    for(int row = 0; row < rowCount ; row++){
        //num-star
        for(int col = 0; col < row; col++){
            cout<<(row+1)<<"*";
        }
        cout<<row+1<<endl;
    } 
   
    return 0;
}