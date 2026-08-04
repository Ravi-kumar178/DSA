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
class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHp;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                minHp.push(lists[i]);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!minHp.empty()) {
            ListNode* front = minHp.top();
            minHp.pop();

            if (head == nullptr && tail == nullptr) {
                head = front;
                tail = head;
            }
            else {
                tail->next = front;
                tail = tail->next;
            }

            if (front->next) {
                minHp.push(front->next);
            }
        }
        return head;
    }
};