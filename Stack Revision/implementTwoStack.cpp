#include<iostream>
using namespace std;

class Stack{
    private:
    int *arr;
    int size;
    int top1;
    int top2;

    public:
    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data){
        if(top2-top1 == 1){
            cout<<"stack overflow, can't be pushed"<<endl;
            return;
        }
        top1 += 1;
        arr[top1] = data;
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"stack overflow, can't be pushed"<<endl;
            return;
        }
        top2 -= 1;
        arr[top2] = data;
    }

    void pop1(){
        if(top1 == -1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top1--;
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top2++;
    }

    int get1(){
        if(top1 == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top1];
    }

    int get2(){
        if(top2 == size){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top2];
    }

    void print1(){
        for(int i = top1; i >= 0; i--){
            cout<<arr[i]<<",";
        }
        cout<<endl;
    }

    void print2(){
        for(int i = top2; i <= size-1; i++){
            cout<<arr[i]<<",";
        }
        cout<<endl;
    }
};

int main(){
    Stack s(10);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    s.push1(5);

    s.print1();
    cout<<"first stack: "<<s.get1()<<endl;
    s.print2();

    s.push2(10);
    s.push2(20);
    s.push2(30);
    s.push2(40);
    s.push2(50);
    
    s.print2();
    cout<<"second stack: "<<s.get2()<<endl;
    // s.push1(6);
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    s.print1();
    s.pop1();
    s.print1();


    return 0;
}