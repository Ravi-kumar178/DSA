class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* evenHead = curr;

        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = evenHead;
        return head;
    }
};