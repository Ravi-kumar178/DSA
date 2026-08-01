/*
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
    int findMedian(Node* root) {
        // Code here
        stack<Node*>s;
        Node* a = root;
        
        int nodeCount = 0;
        
        while(a || !s.empty()){
            while(a){
                s.push(a);
                a = a->left;
            }
            nodeCount += 1;
            Node* atop = s.top();
            s.pop();
            a = atop->right;
        }
        
        int medianCount = 0;
        
        if(nodeCount&1) medianCount = (nodeCount+1)/2;
        else medianCount = nodeCount/2;
        
        Node *b = root;
        int count = 0;
        
        while(b || !s.empty()){
            while(b){
                s.push(b);
                b = b->left;
            } 
            
            Node* btop = s.top();
            s.pop();
            
            count += 1;
            if(count == medianCount) return btop->data;
            
            b = btop->right;
            
        }
        
        return -1;
    }
};