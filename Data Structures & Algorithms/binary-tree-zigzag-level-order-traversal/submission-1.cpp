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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);

        vector<vector<int>> ans;
        int order = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> v(n);
            if(!order){
                for(int i = 0 ;i<n;i++){
                    TreeNode *node = q.front();
                    q.pop();
                    v[i] = node->val;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                order = 1;

            }
            else{
                for(int i = 0 ;i<n;i++){
                    TreeNode *node = q.front();
                    q.pop();
                    v[n-i-1] = node->val;
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                order = 0;

            }
            
            ans.push_back(v);
        }
        return ans;
        
    }
};