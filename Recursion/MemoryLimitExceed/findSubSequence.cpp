//find subsequence
#include<iostream>
#include<string>
using namespace std;

void subSequence(string s, string output, int index){
    if(index >= s.size()){
        cout<<"->"<<output<<endl;
        return;
    }
    char ch = s[index];
    
    subSequence(s,output,index+1);
    output.push_back(ch);
    subSequence(s,output,index+1);
}

int main(){
    string s = "abc";
    string output = "";
    int index = 0;
    subSequence(s,output,index);
    return 0;
}