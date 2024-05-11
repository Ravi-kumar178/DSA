#include<iostream>
#include<string.h>
using namespace std;

bool palindrome(char ch[], int length){
    int i = 0;
    int j = length - 1;
    while(i <= j){
        if(ch[i] != ch[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    char ch[100];
    cin.getline(ch,100);
    int length = strlen(ch);
    cout<<"The length of the string is: "<<length<<endl;
    bool isPalindrome = palindrome(ch,length);
    if(isPalindrome){
        cout<<"String is palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }
    return 0;
}