/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void leftBoundary(Node* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        ans.push_back(root->data);
        
        if(root->left){
            leftBoundary(root->left, ans);
        }
        else{
            leftBoundary(root->right, ans);
        }
        return;
    };
    void bottomBoundary(Node* root, vector<int>& ans){
      if(!root) return;
      if(!root->left && !root->right) ans.push_back(root->data);
      
      bottomBoundary(root->left,ans);
      bottomBoundary(root->right,ans);
      return;
    };
    void rightBoundary(Node* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        
        if(root->right){
            rightBoundary(root->right, ans);
        }
        else{
            rightBoundary(root->left, ans);
        }
        ans.push_back(root->data);
        return;
    };
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!root) return ans;
        
        ans.push_back(root->data);
        
        if(!root->left && !root->right) return ans;
        
        if(root->left) leftBoundary(root->left, ans);
        bottomBoundary(root,ans);
        if(root->right) rightBoundary(root->right,ans);
        
        return ans;
    }
};