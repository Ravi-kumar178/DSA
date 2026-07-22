
class Solution {
public:
    void createMapping(unordered_map<int,int>& valueToIndexMapping, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            valueToIndexMapping[inorder[i]] = i;
        }
    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& valueToIndexMapping, int& preOrderIndex, int inOrderStart, int inOrderEnd){

        if(preOrderIndex > preorder.size()-1 || inOrderStart > inOrderEnd) return nullptr;

        int element = preorder[preOrderIndex];
        TreeNode* newNode = new TreeNode(element);
        preOrderIndex++;

        int position = valueToIndexMapping[element];

        newNode->left = createTree(preorder,inorder,valueToIndexMapping, preOrderIndex, inOrderStart, position-1);
        newNode->right = createTree(preorder,inorder,valueToIndexMapping, preOrderIndex, position+1, inOrderEnd);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>valueToIndexMapping;
        createMapping(valueToIndexMapping, inorder);
        int preOrderIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size()-1;
        
        TreeNode* root = createTree(preorder,inorder, valueToIndexMapping, preOrderIndex, inOrderStart, inOrderEnd);
        
        return root;
    }
};