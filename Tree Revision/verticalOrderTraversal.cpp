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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mp;

        while (!q.empty()) {
            auto queueFront = q.front();
            q.pop();

            TreeNode* front = queueFront.first;
            auto p = queueFront.second;

            int row = p.first, col = p.second;

            mp[col][row].insert(front->val);

            if (front->left) {
                q.push({front->left, {row + 1, col - 1}});
            }
            if (front->right) {
                q.push({front->right, {row + 1, col + 1}});
            }
        }

        for (auto it : mp) {
            auto colMap = it.second;
            vector<int> arr;

            for (auto newIt : colMap) {
                auto mpset = newIt.second;
                arr.insert(arr.end(), mpset.begin(), mpset.end());
            }
            ans.push_back(arr);
            arr.clear();
        }
        return ans;
    }
};