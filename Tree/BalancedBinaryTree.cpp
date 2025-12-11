/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == 0) return 0;

        int leftSubTree = height(root->left);
        int rightSubTree = height(root->right);
        int maxAns = max(leftSubTree,rightSubTree)+1;
        return maxAns;
    };

    bool isBalanced(TreeNode* root) {

        //base case
        if(root == 0) return true;

        //solve 1 case
        int currNodeLeftTreeHeight = height(root->left);
        int currNodeRightTreeHeight = height(root->right);
        int currNodeAns = abs(currNodeLeftTreeHeight-currNodeRightTreeHeight);
        bool balancedAns = currNodeAns <= 1;

        //recursion left subtree ke svi nodes or right sub tree ke svi nodes ko smbhal lega
        bool leftSubTree = isBalanced(root->left);
        bool rightSubTree = isBalanced(root->right);

        if(balancedAns && leftSubTree && rightSubTree){
            return true;
        }
        return false;

        
    }
};