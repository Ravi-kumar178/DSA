struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *midHead(ListNode *&head) {
        ListNode *fast = head, *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode *reverseLL(ListNode *&head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool compareLL(ListNode *&head, ListNode *&secondHead) {
        while (secondHead != nullptr) {
            if (head->val != secondHead->val)
                return false;
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *middleNode = midHead(head);
        // cout<<middleNode->val<<endl;
        ListNode *secondHead = middleNode->next;
        // cout<<secondHead->val<<endl;
        // reverse the second half
        ListNode *reversedSecondHalf = reverseLL(secondHead);
        middleNode->next = nullptr;
        // compare the first half and second half of ll
        return compareLL(head, reversedSecondHalf);
    }
};
