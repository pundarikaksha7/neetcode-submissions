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
    int dfs(TreeNode *root,unordered_map<TreeNode*,int>&v){
        if(!root) return 0;
        int left=0,right=0;
        if(root->left!=NULL &&v.find(root->left)==v.end()) left=dfs(root->left,v);
        if(root->right!=NULL && v.find(root->right)==v.end()) right =dfs(root->right,v);
        v[root] = abs(right-left);
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*,int> v;
        dfs(root,v);
        for(auto c:v){
            if(c.second>1) return false;
        }
        return true;

        
    }
};
