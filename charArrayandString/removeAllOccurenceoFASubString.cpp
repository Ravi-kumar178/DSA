class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            //string present
            //erase now
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};