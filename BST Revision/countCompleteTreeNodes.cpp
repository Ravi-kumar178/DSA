// class Solution {
// public:
//     void countN(TreeNode* root, int& count){
//         if(!root) return;
//         count += 1;
//         countN(root->left,count);
//         countN(root->right,count);
//         return;
//     }
//     int countNodes(TreeNode* root) {
//         int count = 0;
//         countN(root,count);
//         return count;
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        TreeNode *leftTree = root, *rightTree = root;
        int lh = 0, rh = 0;
        while (leftTree) {
            lh++;
            leftTree = leftTree->left;
        }
        while (rightTree) {
            rh++;
            rightTree = rightTree->right;
        }

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};