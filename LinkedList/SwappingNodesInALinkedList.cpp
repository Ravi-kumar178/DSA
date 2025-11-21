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

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstNode = head;
        ListNode* lastNode = head;
        int a = k;
        while(a > 1){
            firstNode = firstNode->next;
            a--;
        }

        int len = getLen(head);
        int b = len-k+1;

        while(b > 1){
            lastNode = lastNode->next;
            b--;
        }

        swap(firstNode->val,lastNode->val);
        return head;
        
    }
};