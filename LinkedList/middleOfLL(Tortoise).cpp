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
    // int getLength(ListNode* head){
    //     ListNode* temp = head;
    //     int count = 0;
    //     while(temp != NULL){
    //         count++;
    //         temp = temp->next;
    //     }
    //     return count;
    // };

    ListNode* middleNode(ListNode* head) {
        // int n = getLength(head);
        // int midPosition = n/2 + 1;
        // int currPosition = 1;
        // ListNode* curr = head;
        // while(currPosition != midPosition){
        //     currPosition++;
        //     curr = curr->next;
        // }
        // return curr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};