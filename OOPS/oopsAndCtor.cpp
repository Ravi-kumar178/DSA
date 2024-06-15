//OOPS -> It is a object oriented programming that is basically aimed to reduce the complexity,
//enhance the maintaibility and extendibility in the functional programming

//class -> It is a custom data types that has a bundle of properties and behaviour .
//class is a blue print by using which we can create an object
//object -> It is an instance of class.

//constructor -> It is a function that is defined inside the class to create an object.
//It is only fun in cpp that has no return type. 
//when we define class then the compiler has default ctor that returns construct and return the object
//during the object creation

//parameterised ctor -> It is a function that is used to create an instance of an object using
// the parameter that is being passed into it to create the object , the parameterised ctor simplify the Coding

//this keyword -> It is a pointer variable that strores the address of current object that is 
//this keyword is pointing towards the current object

#include<iostream>
#include<string>
using namespace std;

class Student{
 private:
   string gfName;
 public:    
    string name;
    int roll;
    int age;
    bool present;
    
    Student(){
        cout<<"Default Ctor is present"<<endl;
    }
    //parameterised Ctor
    Student(string _name,int _roll,int _age,bool _present, string _gfName){
        cout<<"parameterised ctor called"<<endl;
        name = _name;
        roll = _roll;
        age = _age;
        present = _present;
        gfName = _gfName;
    }
    
    Student(string name, int roll, int age, bool present){
        cout<<"This keyword ctor is called"<<endl;
        this->name = name;
        this->roll = roll;
        this->age = age;
        this->present = present;
        this->gfName = gfName;
    }
    
    void eat(){
        cout<<"Eatting"<<endl;
    }
    void code(){
        cout<<"Coding"<<endl;
    }
    void sleep(){
        cout<<"Sleep"<<endl;
    }
  private:
    void luv(){
        cout<<"Tuta jo kvi tara"<<endl;
    }
};

int main(){
    Student ravi;
    ravi.name = "Ravi";
    cout<<ravi.name<<endl;
    ravi.roll = 33;
    ravi.age = 24;
    ravi.present = 1;
    cout<<ravi.present<<endl;
    ravi.eat();
    ravi.code();
   // ravi.gfName = "Raj";//private
   
   Student s2("Rohit",48,24,1,"Sakshi");
   cout<<s2.name<<endl;
   cout<<s2.age<<endl;
   cout<<s2.roll<<endl;
   cout<<s2.present<<endl;
   //cout<<s2.gfName<<endl;//private
   s2.code();
   
   
   Student s3("Roshan",52,24,1);
   cout<<s3.name<<endl;
    
    return 0;
}