//Global Variable -> The variable that is defined outside the function and is accessed inside the function 
//is called as global variable, It can be redefined and accessed thorough scope resolution operator(::)

//Local Variable -> The variable that is defined iside the function and is accessed through out the function.
//local variable has high priority than global variable;
#include<iostream>
using namespace std;

int x = 10;
void fun(){
   // int x = x;//initializing with itself -> give 0;
    int x = 20;
    cout<<"X is: "<<x<<endl; //10//20
    cout<<"x is: "<<::x<<endl;
}

int main(){
    fun();
    return 0;
}