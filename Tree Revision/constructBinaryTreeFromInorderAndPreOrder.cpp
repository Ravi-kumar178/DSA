Problems
Contest
Discuss
Interview
Store
Search


0
0Streaks
Now or Never!
DCC Badge

avatar
Avatar
Ravithakur1-_
Access all features with our Premium subscription!
myLists
My Lists
notebook
Notebook
progress
Progress
points
Points
Try New Features
Orders
My Playgrounds
Settings
Appearance
Sign Out
Premium
Submissions Detail -
Construct Binary Tree from Preorder and Inorder Traversal
Accepted
203 / 203 testcases passed
Ravithakur1-_
Ravithakur1-_
submitted at Jul 22, 2026 17:21

Solution
Runtime
3
ms
Beats
72.88%
Memory
27.48
MB
Beats
54.78%
Code
C++
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
    void createMapping(unordered_map<int,int>& valueToIndexMapping, vector<int>& inorder){
        for(int i = 0; i < inorder.size(); i++){
            valueToIndexMapping[inorder[i]] = i;
        }
    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& valueToIndexMapping, int& preOrderIndex, int inOrderStart, int inOrderEnd){

        if(preOrderIndex > preorder.size()-1 || inOrderStart > inOrderEnd) return nullptr;

        int element = preorder[preOrderIndex];
        TreeNode* newNode = new TreeNode(element);
        preOrderIndex++;

        int position = valueToIndexMapping[element];

        newNode->left = createTree(preorder,inorder,valueToIndexMapping, preOrderIndex, inOrderStart, position-1);
        newNode->right = createTree(preorder,inorder,valueToIndexMapping, preOrderIndex, position+1, inOrderEnd);

        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>valueToIndexMapping;
        createMapping(valueToIndexMapping, inorder);
        int preOrderIndex = 0;
        int inOrderStart = 0;
        int inOrderEnd = inorder.size()-1;
        
        TreeNode* root = createTree(preorder,inorder, valueToIndexMapping, preOrderIndex, inOrderStart, inOrderEnd);
        
        return root;
    }
};
View less
 
Write your notes here
Select related tags
0/5
Back to Problem
Copyright © 2026 LeetCode
Download App
Help Center
Bug Bounty
Assessment
Terms
Privacy Policy

India
