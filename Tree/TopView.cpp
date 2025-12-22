

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int>hdToNodemap;
        queue<pair<Node*,int>>q;
        vector<int>ans;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front(); q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(hdToNodemap.find(hd) == hdToNodemap.end()){
                hdToNodemap[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
  
        for(auto it:hdToNodemap){
            ans.push_back(it.second);
        }
        return ans;
    }
};