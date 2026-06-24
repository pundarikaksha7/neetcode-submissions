/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *,bool> foundp,foundq;
    bool find(TreeNode *root, TreeNode *node,unordered_map<TreeNode*,bool> &foundnode){
        if(!root) return false;

        if(root==node) return foundnode[root] = true;

        // if(foundnode.find(root)!=foundnode.end()) return foundnode[root];

        return foundnode[root] = (find(root->left,node,foundnode) || find(root->right,node,foundnode));
    }
    TreeNode *ans;
    void dfs(TreeNode *root, TreeNode*p, TreeNode *q){
        if(!root) return;

        if(foundp.find(root)!=foundp.end() && foundp[root] && foundq.find(root)!=foundq.end() && foundq[root]){
            ans = root;
        }
        dfs(root->left,p,q);
        dfs(root->right,p,q);

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool finda = find(root,p,foundp);
        bool findb = find(root,q,foundq);
        dfs(root,p,q);
        return ans;
        
    }
};