#include<utility>
class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            // pair<int,int>p = make_pair(value,value);
            pair<int,int>p = {value,value};
            st.push_back(p);
        }
        else{
            pair<int,int>p = {value,min(value,st.back().second)};
            st.push_back(p);
        }

    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else{
            st.pop_back();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */