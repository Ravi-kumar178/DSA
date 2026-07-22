/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
#include<map>

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>hdToNode;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front(); q.pop();
            
            int hd = temp.second;
            Node* frontNode = temp.first;
            
            if(hdToNode.find(hd) == hdToNode.end()){
                hdToNode[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto it: hdToNode){
            ans.push_back(it.second);
        }
        return ans;
    }
};