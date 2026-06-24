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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return {};
        ans.push_back({root->val});

        q.push(root);

        while(!q.empty()){
            
            int layersize = q.size();
            vector<int> thislayer;

            for(int i = 0 ;i<layersize;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left){
                    thislayer.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    thislayer.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            if(thislayer.size())ans.push_back(thislayer);
        }
        return ans;
        
    }
};
