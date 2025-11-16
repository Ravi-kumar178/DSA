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

    void printLL(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }

    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool compareLL(ListNode* head, ListNode* head2){
        while(head2 != NULL){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //find middle node 
        ListNode* midNode = middleNode(head);
        //break two node (head->midNode) && (midNode+1->tail)
        ListNode* head2 = midNode->next;
        midNode->next = NULL;
        //reverse second node
        ListNode* newHead = reverseLL(head2);
        //compare both and return
        bool ans = compareLL(head,newHead);
        return ans;
    }
};