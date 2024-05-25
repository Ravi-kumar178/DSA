#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string s = "RAVI KUMAR";
    map<char,int>mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
    return 0;
}