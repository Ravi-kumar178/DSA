#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string s = "RAVIRKUMAR";
    map<char,int>mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    
    int maxi = 0;
    char ch;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > maxi){
            maxi = it->second;
            ch = it->first;
        }
    }
    cout<<ch<<" : "<<maxi<<endl;
    return 0;
}