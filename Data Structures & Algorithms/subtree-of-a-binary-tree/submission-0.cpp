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
    bool same(TreeNode *p, TreeNode *q){
        if(!p && q) return 0;
        if(p && !q) return 0;
        if(!p && !q) return 1;
        if(p->val != q->val) return 0;
        return (same(p->left,q->left) && same(p->right,q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        if(same(root,subRoot)) return 1;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};
