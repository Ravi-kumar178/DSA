class Node {
  public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(0), right(0) {}
};

class Solution {
  public:
    Node *insert(Node *root, int val, int &succ) {
        if (!root)
            return new Node(val);

        if (val >= root->data) {
            root->right = insert(root->right, val, succ);
        } else {
            succ = root->data;
            root->left = insert(root->left, val, succ);
        }
        return root;
    }
    vector<int> replaceWithLeastGreater(vector<int> &arr) {
        // User to implement the actual logic here
        vector<int> ans(arr.size(), -1);
        Node *root = nullptr;

        for (int i = arr.size() - 1; i >= 0; i--) {
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};