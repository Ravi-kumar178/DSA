#include<iostream>
#include<string.h>
using namespace std;

void replaceSpace(char ch[]){
    int i = 0;
    while(ch[i] != '\0'){
        if(ch[i] == ' '){
            ch[i] = '@';
        }
        i++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = strlen(ch);
    cout<<"The length of the string is: "<<length<<endl;
    replaceSpace(ch);
    cout<<ch;
    return 0;
}