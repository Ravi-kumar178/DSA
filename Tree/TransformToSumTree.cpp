/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node* node){
        if(!node) return 0;
        
        if(!node->left && !node->right){
            int temp = node->data;
            node->data = 0;
            return temp;
        }
        
        int leftSum = sum(node->left);
        int rightSum = sum(node->right);
        
        int temp = node->data;
        node->data = leftSum + rightSum;
        return temp + node->data;
    }
    
    void toSumTree(Node *node) {
        // Your code here
        sum(node);
    }
};