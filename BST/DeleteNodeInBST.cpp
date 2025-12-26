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
    TreeNode* minVal(TreeNode* root){
        if(!root) return NULL;

        TreeNode* temp = root;
        while(temp->left){
            temp = temp->left;
        }
        return temp;
    };
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key == root->val){
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->left && root->right){
                TreeNode* childrenNode = root->right;
                delete root;
                return childrenNode;
            }
            else if(root->left && !root->right){
                TreeNode* childrenNode = root->left;
                delete root;
                return childrenNode;
            }
            else{
                TreeNode* maxi = minVal(root->right);
                root->val = maxi->val;
                root->right = deleteNode(root->right,maxi->val);
                return root;
            }
        }
        else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};