/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* a, Node* b){
        if(!b) return a;
        if(!a) return b;
        Node* ans = NULL;
        
        if(a->data < b->data){
            ans = a;
            a->bottom = merge(a->bottom,b);
        }
        else{
            ans = b;
            b->bottom = merge(a,b->bottom);
        }
        return ans;
    }
    
    Node *flatten(Node *root) {
        // code here
        if(!root) return 0;
        Node* ans = merge(root,flatten(root->next));
        return ans;
    }
};