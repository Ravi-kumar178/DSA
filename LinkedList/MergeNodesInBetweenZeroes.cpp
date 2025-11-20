class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* newHead = 0;
        ListNode* newTail = 0;
        while(curr){
            int sum = 0;
            while(curr->val){
                sum += curr->val;
                curr = curr->next;
            }
            ListNode* newNode = new ListNode(sum);
            //insert at tail;
            if(!newHead){
                newHead = newNode;
                newTail = newNode;
            }
            else{
                newTail->next = newNode;
                newTail = newNode;
            }
            curr = curr->next;
        }
        return newHead;
    }
};