class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {

    }
    
    void push(int x) {
        while(!q1.empty()){
            int temp = q1.front(); q1.pop();
            q2.push(temp);
        }
        q1.push(x);
        while(!q2.empty()){
            int temp = q2.front();q2.pop();
            q1.push(temp);
        }
    }
    
    int pop() {
        int temp = q1.front();q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

