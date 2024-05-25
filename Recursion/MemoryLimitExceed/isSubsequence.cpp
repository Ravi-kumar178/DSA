class Solution {
public:
    void subSequence(string t, int index, vector<string>& ans,string output){
        if(index >= t.size()){
            ans.push_back(output);
            return;
        }
        char ch = t[index];
        //exclude
        subSequence(t,index+1,ans,output);
        output.push_back(ch);
        subSequence(t,index+1,ans,output);
    }
    bool isSubsequence(string s, string t) {
        vector<string>ans;
        int index = 0;
        string output = "";
        subSequence(t,index,ans,output);

        for(string str: ans){
            if(str == s){
                return true;
            }
        }
        return false;
    }
};