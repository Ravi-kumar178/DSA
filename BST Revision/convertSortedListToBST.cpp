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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createArray(ListNode* head, vector<int>& inorderArray){
        if(!head) return;

        inorderArray.push_back(head->val);
        createArray(head->next,inorderArray);

        return;
    }

    TreeNode* createTree(vector<int>& inorderArray, int start, int end){
        if(start > end) return nullptr;

        int mid = start + (end-start)/2;
        TreeNode* newNode = new TreeNode(inorderArray[mid]);

        newNode->left = createTree(inorderArray, start, mid-1);
        newNode->right = createTree(inorderArray, mid+1, end);

        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;

        vector<int>inorderArray;
        createArray(head,inorderArray);
        int start = 0, end = inorderArray.size()-1;
        TreeNode* root = createTree(inorderArray,start,end);
        return root;
    }
};