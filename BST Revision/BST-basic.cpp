class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) {
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BST {
  private:
    TreeNode *root;
    TreeNode *insertHelper(TreeNode *root, int value) {
        if (!root) {
            TreeNode *newNode = new TreeNode(value);
            return newNode;
        }

        if (value > root->val) {
            root->right = insertHelper(root->right, value);
        } else {
            root->left = insertHelper(root->left, value);
        }
        return root;
    }

    bool found(TreeNode *root, int target) {
        if (!root)
            return false;

        if (root->val == target)
            return true;

        bool leftAns = false, rightAns = false;
        if (target > root->val) {
            rightAns = found(root->right, target);
        } else {
            leftAns = found(root->left, target);
        }

        return rightAns || leftAns;
    }

    int max(TreeNode *root) {
        if (!root)
            return -1;
        while (root->right)
            root = root->right;
        return root->val;
    }

    TreeNode *deleteNode(TreeNode *root, int target) {
        if (!root)
            return root;

        if (root->val == target) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left && root->right) {
                TreeNode *childNode = root->right;
                root->right = nullptr;
                delete root;
                return childNode;
            } else if (root->left && !root->right) {
                TreeNode *childNode = root->left;
                root->left = nullptr;
                delete root;
                return childNode;
            } else {
                int maxValue = max(root->left);
                root->val = maxValue;
                root->left = deleteNode(root->left, maxValue);
                return root;
            }
        } else if (target > root->val) {
            root->right = deleteNode(root->right, target);
        } else {
            root->left = deleteNode(root->left, target);
        }
        return root;
    }

    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);

        return;
    }

    void preorder(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);

        return;
    }

    void postorder(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);

        return;
    }

  public:
    BST() {
        // Constructor for initializing BST
        root = nullptr;
    }

    void insert(int value) {
        // Insert a value in the BST
        root = insertHelper(root, value);
        return;
    }

    bool search(int value) {
        bool isFound = found(root, value);
        return isFound;
    }

    void deleteNode(int value) {
        // Delete a node from the BST
        root = deleteNode(root, value);
        return;
    }

    vector<int> inorderTraversal() {
        // Return inorder traversal as a vector
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    vector<int> preorderTraversal() {
        // Return preorder traversal as a vector
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

    vector<int> postorderTraversal() {
        // Return postorder traversal as a vector
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};