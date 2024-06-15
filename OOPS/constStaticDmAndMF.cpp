//const keyword -> The const keyword is used to declare the variable,function and object 
//that is immutable that is its value can't be changed after initialisation.

//the value that is present at the memory address of the variable that is declared using const
//keyword is changed using the pointer

//static data member -> The variable is going to share memory with all of the class instance.
//static member function -> There is no instance of that class being passed into that method.

#include<iostream>
using namespace std;

class Student{
public:    
  static int x;
  static int y;
  
  void fun() const{
      cout<<x<<" "<<y<<endl;
  }
};

int Student::x;
int Student::y;

int main(){
     // const int x = 10;
     //x = 20;
     // cout<<x<<endl;//10
    
   const int *a = new int(2);
   
   int b = 50;
    a = &b;
    cout<<"a is: "<<*a<<endl; 
    
   // Student s1{10,20};
   // s1.fun();
    
    // Student s2{30,40};
    // s2.fun();
     
   Student s1;
   s1.x = 10;
   s1.y = 20;
   s1.fun();
   
   Student s2;
   s2.x = 30;
   s2.y = 40;
   s1.fun();
   s2.fun();
    return 0;
}