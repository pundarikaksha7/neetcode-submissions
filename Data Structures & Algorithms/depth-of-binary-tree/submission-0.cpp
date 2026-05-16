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
    void dfs(TreeNode *root, int len, int &maxlen){
        if(root==nullptr)return ;
        maxlen = max(len,maxlen);
        dfs(root->left,len+1,maxlen);
        dfs(root->right,len+1,maxlen);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxlen = 1;
        dfs(root,1,maxlen);
        return maxlen;

        
    }
};
