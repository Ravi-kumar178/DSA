class Solution {
public:
    void buildAns(stack<string>& st, string& ans){
        if(st.empty()) return;

        string temp = st.top();
        st.pop();

        buildAns(st,ans);
        ans += temp;
    }
    string simplifyPath(string path) {
        //init
        stack<string>st;
        int i = 0;

        while(i < path.size()){
            int start = i;
            int end = start+1;

            while(end < path.size() && path[end] != '/'){
                end++;
            }
            string miniString = path.substr(start,end-start);
            i = end;

            if(miniString == "/" || miniString == "/."){
                continue;
            }
            else if( miniString != "/.."){
                st.push(miniString);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans = st.empty()?"/":"";
        buildAns(st,ans);
        return ans;
    }
};