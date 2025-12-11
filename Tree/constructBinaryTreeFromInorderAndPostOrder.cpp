class Solution {
public:
    void createMapping(map<int,int> &valueToIndexMapping, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            valueToIndexMapping[inorder[i]] = i;
        }
    }

    TreeNode* constructTreeByPostAndInOrder(map<int,int> &valueToIndexMapping, vector<int>postorder, int& postorderIndex, vector<int> inorder, int inorderStart, int inorderEnd){
        if(postorderIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(element);

        int position = valueToIndexMapping[element];

        root->right = constructTreeByPostAndInOrder(valueToIndexMapping,postorder,postorderIndex,inorder, position+1, inorderEnd);
        root->left = constructTreeByPostAndInOrder(valueToIndexMapping,postorder,postorderIndex,inorder, inorderStart, position-1);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>valueToIndexMapping;
        createMapping(valueToIndexMapping, inorder);
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        TreeNode* root = constructTreeByPostAndInOrder(valueToIndexMapping,postorder, postorderIndex, inorder, inorderStart, inorderEnd);
        return root;
    }
};