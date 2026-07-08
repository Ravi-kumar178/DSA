    #include<iostream>
    #include<stack>

    using namespace std;

    
    bool isSorted(stack<int> &st) {
        // recursive code here
        if(st.empty()) return true;

        int top = st.top();
        st.pop();
        if(!st.empty() && st.top() < top){
            st.push(top);
            return false;
        }

        bool ans = isSorted(st);
        st.push(top);
        return ans;
    }

    int main(){
        stack<int>s;
        s.push(9);
        s.push(4);
        s.push(2);

        cout<<isSorted(s)<<endl;
        while(!s.empty()){
            cout<<s.top()<<",";
            s.pop();
        }
        return 0;
    }