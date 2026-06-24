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
    bool ans = true;
    int maxi(TreeNode *root){
        if(!root) return INT_MIN;
        cout<<root->val<<endl;
        return max({root->val,maxi(root->left),maxi(root->right)});
    }
    int mini(TreeNode *root){
        if(!root) return INT_MAX;

        return min({root->val,mini(root->right),mini(root->left)});
    }
    void dfs(TreeNode *root){
        if(!root) return;

        int maxvalleft = maxi(root->left);
        int minvalright = mini(root->right);
        int node = root->val;

        ans = ans && (node>maxvalleft && node<minvalright);
        
        dfs(root->left);
        dfs(root->right);

    }


    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
