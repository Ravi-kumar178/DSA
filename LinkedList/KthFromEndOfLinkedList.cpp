/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getLength(Node* head){
      int len = 0;
      Node* temp = head;
      while(temp != NULL){
          len++;
          temp = temp->next;
      }
      return len;
    };
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* temp = head;
        int len = getLength(temp);
        if(k > len) return -1;
        int nodePos = len-k+1;
        while(nodePos > 1){
            temp = temp->next;
            nodePos--;
        }
        return temp->data;
    }
};