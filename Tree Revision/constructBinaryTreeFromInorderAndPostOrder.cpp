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
    void createMapping(unordered_map<int,int>& mp, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return;
    }

    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& mp, int& postorderIndex, int inorderStart, int inorderEnd){
        if(postorderIndex < 0 || inorderStart > inorderEnd) return nullptr;

        int element = postorder[postorderIndex];
        TreeNode* newNode = new TreeNode(element);
        postorderIndex--;

        int position = mp[element];

        newNode->right = createTree(inorder, postorder, mp, postorderIndex, position+1, inorderEnd);
        newNode->left = createTree(inorder, postorder, mp, postorderIndex, inorderStart, position-1);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        createMapping(mp,inorder);
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;

        TreeNode* root = createTree(inorder,postorder, mp, postorderIndex, inorderStart, inorderEnd);

        return root;
    }
};