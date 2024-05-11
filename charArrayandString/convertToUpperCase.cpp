#include<iostream>
#include<string.h>
using namespace std;

void convertToUpperCase(char ch[],int length){
    int i = 0;
    while(ch[i] != '\0'){
        if(ch[i] >= 'a' && ch[i] <= 'z'){
            cout<<"i: "<<i<<endl;
            ch[i] = ch[i]-'a'+'A';
        }
        i++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = strlen(ch);
    cout<<"The length of the string is: "<<length<<endl;
    convertToUpperCase(ch,length);
    cout<<ch;
    return 0;
}