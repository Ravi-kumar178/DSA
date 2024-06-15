//copy constructor 
//getter -> It is a function that is defined inside the public access modifier to access the 
//data member that is presnt inside inside the private access modifier.
//setter -> It is a function that is defined inside the public access modifier of class to
//update the data member that is present inside the private access modifier.
#include<iostream>
#include<string>
using namespace std;

class Student{
  private:
   string gfName;
  public:
    string name;
    int age;
    int roll;
    bool present;
    
    //getter
    string getGfName(){
        return gfName;
    }
    //setter
    void setGfName(string gf){
        this->gfName = gf;
    }
    
    Student(){
        cout<<"Default Ctor called"<<endl;
    }
    
    Student(string name,int age,int roll,bool present,string gfName){
        cout<<"Parameterised ctor called"<<endl;
        this->name = name;
        this->age = age;
        this->roll = roll;
        this->present = present;
        this->gfName = gfName;
    }
    
    Student(Student& srcobj){
        cout<<"Copy ctor called"<<endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->roll = srcobj.roll;
        this->present = srcobj.present;
        this->gfName = srcobj.gfName;
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
   
};

int main(){
    Student s1;
    Student s2("Ravi",24,33,1,"Raj");
    cout<<s2.name<<endl;
    //cout<<s2.gfName<<endl;
    cout<<s2.getGfName()<<endl;
    s1 = s2;
    cout<<s1.name<<endl;
    
    Student s3 = s1;
    cout<<"S3: "<<s3.name<<endl;
    cout<<s3.getGfName()<<endl;
    s2.setGfName("Chutki");
    cout<<"s2: "<<s2.getGfName()<<endl;
    
    Student s4 = s2;
    cout<<"s4: "<<s4.name<<endl;
    cout<<"s4: "<<s4.getGfName()<<endl;
    return 0;
}