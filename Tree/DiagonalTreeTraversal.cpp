/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int>ans;
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            
            while(front){
                ans.push_back(front->data);
                if(front->left) q.push(front->left);
                front = front->right;
            }
        }
        return ans;
    }
};