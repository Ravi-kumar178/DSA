#include<iostream>
using namespace std;

class Stack{
    private:
        int *arr;
        int size;
        int top;
    
    public:
        Stack(int _size){
            arr = new int[_size];
            this->size = _size;
            this->top = -1;
        }

        void push(int data){
            if(top == size){
                cout<<"Stack Overflow, can't pushed"<<endl;
                return;
            }
            top = top+1;
            arr[top] = data;
        }

        int getTop(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }

        int getSize(){
            return top+1;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack underflow"<<endl;
                return;
            }
            top--;
        }

        bool isEmpty(){
            if(top == -1) return true;
            return false;
        }

        void isSwap(Stack &other){
            int* tempArr = this->arr;
            this->arr = other.arr;
            other.arr = tempArr;

            int size = this->size;
            this->size = other.size;
            other.size = size;

            int top = this->top;
            this->top = other.top;
            other.top = top;
            return;
        }
};

int main(){
    Stack st(5);
    Stack st1(5);

    cout<<"stack is empty: "<<st.isEmpty()<<endl;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    st1.push(50);

    cout<<"stack top element: "<<st.getTop()<<endl;
    cout<<"stack size: "<<st.getSize()<<endl;

    st.pop();
    cout<<"stack top element: "<<st.getTop()<<endl;

    st.isSwap(st1);

    cout<<"stack st top element: "<<st.getTop()<<endl;
    cout<<"stack st1 top element: "<<st1.getTop()<<endl;

}