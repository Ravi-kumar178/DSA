class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch: s){
            if(ch == ']'){
                string strignToBeRepeated = "";
                while(!st.empty() && st.top() != "["){
                    strignToBeRepeated += st.top();
                    st.pop();
                }
                //remove [
                    st.pop();
                
                string numberOfTimesToBeRepeated = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numberOfTimesToBeRepeated += st.top();
                    st.pop();
                }
                reverse(numberOfTimesToBeRepeated.begin(),numberOfTimesToBeRepeated.end());
                int n = stoi(numberOfTimesToBeRepeated);
                string appendedToStack = "";
                while(n > 0){
                    appendedToStack += strignToBeRepeated;
                    n--;
                }
                st.push(appendedToStack);
            }
            else{
                string temp = "";
                temp += ch;
                st.push(temp);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};