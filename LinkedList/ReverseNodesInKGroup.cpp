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
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        //case1
        int len = getLen(head);
        if(len < k) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* newNode = curr->next;
        int pos = 1;
        while(pos <= k){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
            pos++;
        }

        if(newNode != NULL){
            ListNode* recursingAns = reverseKGroup(newNode,k);
            head->next = recursingAns;
        }
        return prev;

    }
};