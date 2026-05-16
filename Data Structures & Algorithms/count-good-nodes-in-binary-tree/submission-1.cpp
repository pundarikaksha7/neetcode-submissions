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

    void dfs(TreeNode *root, int maxyet, int &res){
        if(!root) return ;
        if(maxyet<=root->val) res++;
        maxyet = max(maxyet,root->val);
        dfs(root->left,maxyet,res);
        dfs(root->right,maxyet,res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        if(!root) return 0;
        int maxyet = root->val;
        dfs(root,maxyet,res);
        return res;
        
    }
};
