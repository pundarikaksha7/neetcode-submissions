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
    int depth (TreeNode *node){
        if(!node) return 0;
        return max(1+depth(node->left),1+depth(node->right));
    }
    int dia = 0;

    void dfs(TreeNode *node){
        if(!node) return ;

        int leftdepth = depth(node->left);
        int rightdepth = depth(node->right);
        dia = max(dia,leftdepth+rightdepth);
        dfs(node->left),dfs(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return dia;
    }
};
