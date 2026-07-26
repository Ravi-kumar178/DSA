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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBST(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode *curr = head, *temp = head, *slow = head, *fast = head;

        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        if (temp != slow) {
            while (temp->next != slow)
                temp = temp->next;
            temp->next = nullptr;
        }

        ListNode* rightList = slow->next;

        TreeNode* newNode = new TreeNode(slow->val);
        if (temp == slow)
            newNode->left = nullptr;
        else {
            newNode->left = createBST(curr);
        }
        newNode->right = createBST(rightList);

        return newNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = createBST(head);
        return root;
    }
};