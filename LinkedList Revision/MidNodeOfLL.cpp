struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
//    int getLength(ListNode* &head){
//         ListNode* temp = head;
//         int count = 0;
//         while(temp != nullptr){
//             count++;
//             temp = temp->next;
//         }
//         return count;
//     }

//     ListNode* findHead(ListNode* head, int position){
//         if(position == 1) return head;
//         head = head->next;
//         return findHead(head,position-1);
//     }
//     ListNode* middleNode(ListNode* head) {
//         int linkedListLength = getLength(head);
//         int position = linkedListLength/2 + 1;
//         return findHead(head,position);
//     }

    ListNode* middleNode(ListNode* head) {
       ListNode* fast = head;
       ListNode* slow = head;

       while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
       }
       return slow;
    }
};
