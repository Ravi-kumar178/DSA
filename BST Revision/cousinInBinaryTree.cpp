/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int levelA = 0, levelB = 0;
    TreeNode *parentX = nullptr, *parentY = nullptr;
    void findLevelAndParentNode(TreeNode*& root, TreeNode* parentNode, int x,
                                int y, int level) {
        if (!root)
            return;

        if (root->val == x) {
            parentX = parentNode;
            levelA = level;
        }
        if (root->val == y) {
            levelB = level;
            parentY = parentNode;
        }

        findLevelAndParentNode(root->left, root, x, y, level + 1);
        findLevelAndParentNode(root->right, root, x, y, level + 1);

        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int level = 1;
        TreeNode* parentNode = nullptr;
        findLevelAndParentNode(root, parentNode, x, y, level);

        return ((levelA == levelB) && (parentX != parentY));
    }
};