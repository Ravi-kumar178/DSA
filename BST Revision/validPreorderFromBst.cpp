class Solution {
public:
    void build(vector<int>& preorder, int& i, int min, int max){
        if(i >= preorder.size()) return ;
        int val = preorder[i];
        if(val < min || val > max) return;

        i++;

        build(preorder,i,min,val);
        build(preorder,i,val,max);
    }
    bool canRepresentBST(vector<int>& preorder) {
        // User to implement the actual logic here
        int i = 0;
        build(preorder,i,INT_MIN,INT_MAX);
        return i == preorder.size();
    }
};