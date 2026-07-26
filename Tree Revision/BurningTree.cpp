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
    TreeNode *findTargetNodeAndMapChildToParentNode(
        TreeNode *root, unordered_map<TreeNode *, TreeNode *> &childToParent,
        int start) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *target = nullptr;

        while (!q.empty()) {
            TreeNode *front = q.front();
            q.pop();

            if (front->val == start) {
                target = front;
            }
            if (front->left) {
                childToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                childToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return target;
    }
    int burningTime(TreeNode *targetNode,
                    unordered_map<TreeNode *, TreeNode *> &childToParent) {
        unordered_map<TreeNode *, bool> isBurnt;
        queue<TreeNode *> q; // currently set on fire
        int T = 0;

        q.push(targetNode);
        isBurnt[targetNode] = true;

        while (!q.empty()) {
            int size = q.size();
            bool isFireSpreaded = false;

            for (int i = 0; i < size; i++) {
                TreeNode *front = q.front();
                q.pop();

                if (front->left && !isBurnt[front->left]) {
                    isFireSpreaded = true;
                    isBurnt[front->left] = true;
                    q.push(front->left);
                }
                if (front->right && !isBurnt[front->right]) {
                    isFireSpreaded = true;
                    isBurnt[front->right] = true;
                    q.push(front->right);
                }
                if (childToParent[front] && !isBurnt[childToParent[front]]) {
                    isFireSpreaded = true;
                    isBurnt[childToParent[front]] = true;
                    q.push(childToParent[front]);
                }
            }
            if (isFireSpreaded)
                T += 1;
        }
        return T;
    }
    int minTime(TreeNode *root, int target) {
        // Placeholder logic to be implemented by user
        unordered_map<TreeNode *, TreeNode *> childToParent;
        TreeNode *targetNode =
            findTargetNodeAndMapChildToParentNode(root, childToParent, target);

        int time = burningTime(targetNode, childToParent);
        return time;
    }
};