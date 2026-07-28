class Solution {
private:
    bool checkDeadEnd(TreeNode* node, int minVal, int maxVal) {
        if (node == nullptr) return false;

        if (minVal == maxVal) return true;

        return checkDeadEnd(node->left, minVal, node->val - 1) ||
               checkDeadEnd(node->right, node->val + 1, maxVal);
    }

public:
    bool isDeadEnd(TreeNode* root) {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};