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
    bool dfs(TreeNode *root,int leftlim , int rightlim){
        if(!root) return 1;

        int val = root->val;

        if(!(val<rightlim && val>leftlim)) return false;
        
        return dfs(root->left,leftlim,val) && dfs(root->right,val,rightlim);
    }
    bool isValidBST(TreeNode* root) {
        int leftlim = INT_MIN,rightlim = INT_MAX;
        return dfs(root,leftlim,rightlim);
        
    }
};
