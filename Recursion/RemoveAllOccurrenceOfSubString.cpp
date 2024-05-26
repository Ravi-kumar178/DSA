class Solution {
public:

    void deleteSubString(string& s, string& part){
        //base condition
        if(s.find(part) == string::npos) return ;
        s.erase(s.find(part),part.size());
        deleteSubString(s,part);
    }

    string removeOccurrences(string s, string part) {
        deleteSubString(s,part);
        return s;
    }
};