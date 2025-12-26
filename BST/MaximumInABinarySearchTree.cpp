int maximumInABinarySearchTree(Node* root){
    if(!root) return 0;
    
    while(root->right){
        root = root->right;
    }
    return root->data;
}