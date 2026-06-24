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
    TreeNode *ans;
    bool find(TreeNode *root, TreeNode *node){
        if(!root) return false;

        if(root==node) return true;

        if(node->val>root->val) return find(root->right,node);
        else return find(root->left,node);
    }
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root) return;

        if(find(root,p) && find(root,q)) ans = root;
        dfs(root->left,p,q);
        dfs(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};
