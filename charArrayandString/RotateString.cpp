class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        goal += goal;
        if(goal.find(s) != string::npos){
            return true;
        }
        return false;
    }
};