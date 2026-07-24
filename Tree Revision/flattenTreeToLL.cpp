/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
*/

class Solution {
  public:
    void flatten(TreeNode *root) {
        // Placeholder for tree flattening logic
        if (!root || (!root->left && !root->right))
            return;

        while (root) {
            TreeNode *temp = root->right;

            if (root->left) {
                TreeNode *leftptr = root->left;

                root->right = leftptr;
                root->left = nullptr;

                while (leftptr->right) {
                    leftptr = leftptr->right;
                }
                leftptr->right = temp;
            }
            root = root->right;
        }
        return;
    }
};