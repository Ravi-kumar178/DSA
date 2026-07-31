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
    vector<int> merge(TreeNode *root1, TreeNode *root2) {
        vector<int> ans;
        stack<TreeNode *> s1, s2;
        TreeNode *a = root1;
        TreeNode *b = root2;

        while (a || b || !s1.empty() || !s2.empty()) {
            while (a) {
                s1.push(a);
                a = a->left;
            }
            while (b) {
                s2.push(b);
                b = b->left;
            }

            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                TreeNode *atop = s1.top();
                s1.pop();
                ans.push_back(atop->val);
                a = atop->right;
            } else {
                TreeNode *btop = s2.top();
                s2.pop();
                ans.push_back(btop->val);
                b = btop->right;
            }
        }
        return ans;
    }
};