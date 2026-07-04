/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
         if(head == nullptr || head->next == nullptr) return;
        //detect whether loop present or not
        
        Node *fast = head, *slow = head;
        
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) break;
        }
        
        if(fast == nullptr) return;
        //find the starting point
        slow = head;
        if(slow == fast){
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = nullptr;
            return;
        }
        while(fast->next != slow->next){
            fast = fast->next;
            slow = slow->next;
        }
        

        fast->next = nullptr;
        return;
    }
};