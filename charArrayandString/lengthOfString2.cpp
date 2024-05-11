#include<iostream>
using namespace std;

int getLength(char ch[]){
    int i = 0;
    int count = 0;
    while(ch[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = getLength(ch);
    cout<<"The length of the string is: "<<length<<endl;
    return 0;
}