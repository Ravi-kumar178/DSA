class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && !q) return false;
        if(!p && q) return false;
        if(!p && !q) return true;

        if(p->val != q->val){
            return false;
        }

        bool option1 = isSameTree(p->left,q->left);
        bool option2 = isSameTree(p->right,q->right);

        if(option1 && option2) return true;
        return false;
    }
};