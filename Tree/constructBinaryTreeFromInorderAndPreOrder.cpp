class Solution {
public:
    void createMapping(map<int,int> &valueToIndexMapping, vector<int> &inorder){
        for(int i = 0; i < inorder.size(); i++){
            valueToIndexMapping[inorder[i]] = i;
        }
    }
    TreeNode* constructTreeByPreAndInOrder(map<int,int> &valueToIndexMapping,  vector<int>& preorder, int &preorderIndex, vector<int>& inorder,int inorderStart, int inorderEnd){
        if(preorderIndex >= preorder.size() || inorderStart > inorderEnd){
            return NULL;
        }

        int element = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(element);

        int position = valueToIndexMapping[element];

        root->left = constructTreeByPreAndInOrder(valueToIndexMapping, preorder,preorderIndex, inorder, inorderStart,position-1);
        root->right = constructTreeByPreAndInOrder(valueToIndexMapping, preorder,preorderIndex, inorder, position+1, inorderEnd);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> valueToIndexMapping;
        createMapping(valueToIndexMapping,inorder);
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;

        TreeNode* root = constructTreeByPreAndInOrder(valueToIndexMapping,
        preorder,preorderIndex,inorder,inorderStart,inorderEnd);
        return root;
    }
};