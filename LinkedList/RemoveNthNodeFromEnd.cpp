/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = getLen(head);
        if(len == 1) return NULL;
        int nodePos = len-n+1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        if(nodePos == 1){
            head = curr->next;
            delete curr;
            return head;
        }
        while(nodePos > 1){
            prev = curr;
            curr = curr->next;
            nodePos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return head;
    }
};