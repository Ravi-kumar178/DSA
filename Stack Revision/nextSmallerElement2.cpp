#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> nextSmaller(vector<int>& arr){
    stack<int>st;
    vector<int>ans(arr.size());
    st.push(-1);

    for(int i = arr.size()-1; i >= 0; i--){
        int curr = arr[i];

        if(curr > st.top()){
            ans[i] = st.top();
            if(st.top() == -1) st.push(curr);
            else st.push(min(curr,st.top()));
        }
        else{
            while(curr <= st.top()){
                st.pop();
            }
            ans[i] = st.top();
            st.push(curr);
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {4, 2, 2, 5, 1, 3, 8};

    vector<int>ans = nextSmaller(arr);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}