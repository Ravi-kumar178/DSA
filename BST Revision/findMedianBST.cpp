/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    double findMedian(TreeNode* root) {
        // Placeholder for median calculation logic
        TreeNode* a = root;
        stack<TreeNode*>s;
        int nodeCount = 0;

        while(a || !s.empty()){
            while(a){
                s.push(a);
                a = a->left;
            }
            nodeCount++;
            TreeNode* atop = s.top(); s.pop();
            a = atop->right; 
        }

        int target = 0;

        if(nodeCount&1) target = nodeCount/2 + 1;
        else target = nodeCount/2;

        a = root;
        int count = 0;
        int firstEle = -1;

        while(a || !s.empty()){
            while(a){
                s.push(a);
                a = a->left;
            }
            count += 1;
            TreeNode* atop = s.top(); s.pop();
            a = atop->right;

            if(count == target){
                firstEle = atop->val;
                break;
            }
        }

        if(nodeCount&1) return (double)firstEle;

        while(a){
            s.push(a);
            a = a->left;
        }

        int secondEle = s.top()->val;

        int sum = firstEle + secondEle;

        return (double)sum/2;
    }
};