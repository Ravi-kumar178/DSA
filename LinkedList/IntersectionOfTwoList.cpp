/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int len1 = getLen(temp1);
        int len2 = getLen(temp2);

        if(len2 > len1){
            int lenDiff = len2 - len1;
            while(lenDiff > 0){
                temp2 = temp2->next;
                lenDiff--;
            }
        }
        else{
            int lenDiff = len1 - len2;
            while(lenDiff > 0){
                temp1 = temp1->next;
                lenDiff--;
            }
        }

        while((temp1 != NULL) && (temp2 != NULL)){
            if(temp1 == temp2){
                return temp1;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};