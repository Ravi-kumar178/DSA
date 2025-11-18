/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(!head) return head;
        //take a iterator pointer and move it to mth node
        Node* it = head;
        for(int i = 0; i < m-1; i++){
            if(!it) return head;
            it = it->next;
        }
        
        //if it comes to be null that means no element is there to delete
        if(!it) return head;
        Node* mthNode = it;
        it = it->next;
        for(int i = 0; i < n; i++){
            if(!it) break;
            Node* temp = it->next;
            delete it;
            it = temp;
        }
        mthNode->next = it;
        Node* recAns = linkdelete(it,n,m);
        return head;
    }
};