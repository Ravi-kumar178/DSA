/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void helper(Node* root, int level, vector<int>&arr){
        if(!root) return;
        
        if(arr.size() < level) arr.push_back(root->data);
        
        helper(root->left, level+1, arr);
        helper(root->right, level+1, arr);
        return;
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>arr;
        int level = 1;
        helper(root,level,arr);
        return arr;
    }
};