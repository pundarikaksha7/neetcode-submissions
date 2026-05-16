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
    bool findNode(TreeNode *root, TreeNode *node){
        if(!root) return 0;
        if(root==node) return 1;
        bool found = 0;
        if(node->val<root->val) found = findNode(root->left,node);
        else found = findNode(root->right,node);
        return found;
    }
    void find(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&lca){
        if(!root) return;
        
        if(findNode(root,p) && findNode(root,q)){ 
        lca = root;
        }
        find(root->left,p,q,lca);
        find(root->right,p,q,lca);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = new TreeNode();
        find(root,p,q,lca);
        return lca;

    }
};
