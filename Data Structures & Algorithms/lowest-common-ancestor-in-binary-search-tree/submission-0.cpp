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
        bool left=0,right=0;
        if(root->left) left = findNode(root->left,node);
        if(root->right) right = findNode (root->right,node);

        return left || right;
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
