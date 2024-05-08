
#include<iostream>
#include<string.h>
using namespace std;

int getLength(char ch[],int size){
    int length = 0;
    int i = 0;
    while(ch[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int size = 100;
    int length = getLength(ch,size);
    cout<<"length is: "<<length<<endl;
   cout<<"str length is: "<<strlen(ch)<<endl;
    return 0;
}