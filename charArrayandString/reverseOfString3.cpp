#include<iostream>
#include<string.h>
using namespace std;



void swapString(char ch[]){
    int i = 0;
    int j = strlen(ch) - 1;
    while(i<=j){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = strlen(ch);
    cout<<"The length of the string is: "<<length<<endl;
    swapString(ch);
    cout<<ch;
    return 0;
}