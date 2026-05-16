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
    int dfs(TreeNode *root,int &maxlen){
         if(root==nullptr) return 0;
         int left_depth = dfs(root->left,maxlen);
         int right_depth = dfs(root->right,maxlen);
         maxlen = max({maxlen,left_depth+right_depth});
         return 1+max({left_depth,right_depth});
         

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxlen = 0;
        dfs(root,maxlen);
        return maxlen;
        
    }
};
