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
    bool dfs(TreeNode *root, int leftlimit, int rightlimit){
        if(!root) return true;

        if(root->val<=leftlimit || root->val>=rightlimit) return false;

        return dfs(root->left,leftlimit,root->val) && dfs(root->right,root->val,rightlimit);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
        
    }
};
