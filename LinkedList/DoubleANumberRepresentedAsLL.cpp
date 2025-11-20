class Solution {
public:
    void multiply(ListNode* head,int& carry){
        if(!head) return;
        multiply(head->next,carry);

        //1 case
        int prod = head->val*2+carry;
        head->val = prod%10;
        carry = prod/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        multiply(head,carry);
        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};