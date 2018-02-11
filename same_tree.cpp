// Leetcode Problem 100 Same Tree
// Given two binary trees, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p->val != q->val)
            return false;
        if (p->left!=NULL && q->left!=NULL && p->right!=NULL && q->right!=NULL)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else if (p->left==NULL && q->left==NULL && p->right!=NULL && q->right!=NULL)
            return isSameTree(p->right, q->right);
        else if (p->left!=NULL && q->left!=NULL && p->right==NULL && q->right==NULL)
            return isSameTree(p->left, q->left);
        else if (p->left==NULL && q->left==NULL && p->right==NULL && q->right==NULL)
            return true;
        else
            return false;
    }
};
*/


// Simplify the code
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        else if (p && q)
            return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right,q->right));
        else 
            return false;
    }
};
