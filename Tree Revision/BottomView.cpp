/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int,int>hdToNode;
        queue<pair<Node*,int>>q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front(); q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            hdToNode[hd] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        vector<int>ans;
        for(auto it: hdToNode){
            ans.push_back(it.second);
        }
        return ans;
    }
};