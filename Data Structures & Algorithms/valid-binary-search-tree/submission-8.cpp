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
    unordered_map<TreeNode*,int> maxleftdp;
    unordered_map<TreeNode*,int> minrightdp;
    int maxi(TreeNode *root){
        if(!root) return INT_MIN;
        cout<<root->val<<endl;
        if(maxleftdp.find(root)!=maxleftdp.end()) return maxleftdp[root];
        return maxleftdp[root] = max({root->val,maxi(root->left),maxi(root->right)});
    }
    int mini(TreeNode *root){
        if(!root) return INT_MAX;
        if(minrightdp.find(root)!=minrightdp.end()) return minrightdp[root];
        return minrightdp[root] = min({root->val,mini(root->right),mini(root->left)});
    }
    void dfs(TreeNode *root){
        if(!root) return;
        int maxvalleft = INT_MIN, minvalright = INT_MAX;
        if(root->left && maxleftdp.find(root->left)!=maxleftdp.end()) maxvalleft = maxleftdp[root->left];
        else maxvalleft = maxi(root->left);
        if(root->right && minrightdp.find(root->right)!=minrightdp.end()) minvalright = minrightdp[root->right];
        else minvalright = mini(root->right); 
        int node = root->val;

        ans = ans && (node>maxvalleft && node<minvalright);
        
        dfs(root->left);
        dfs(root->right);

    }


    bool isValidBST(TreeNode* root) {
        dfs(root);
        
        
        // treenode, maxleft,minright
        return ans;
    }
};
