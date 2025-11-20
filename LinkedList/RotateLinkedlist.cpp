class Solution {
public:
    int getLen(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = getLen(head);
        int newRotateK = k%len;

        if(!newRotateK) return head;

        //find last node pos
        int lastNodePos = len-newRotateK-1;
        ListNode* lastNode = head;
        while(lastNodePos){
            lastNode = lastNode->next;
            lastNodePos--;
        }
        
        //new head
        ListNode* newHead = lastNode->next;
        //make lastNode pointed to null
        lastNode->next = NULL;
        ListNode* temp = newHead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return newHead;
    }
};