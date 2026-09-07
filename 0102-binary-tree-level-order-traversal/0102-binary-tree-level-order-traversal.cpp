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
    int levels(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = levels(root->left);
        int r = levels(root->right);
        return 1 + max(l, r);
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        int n = levels(root);
        vector<vector<int>> ans(n,vector<int>(0));
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(q.size() > 0){
            pair <TreeNode*, int> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int lvl = front.second;
            ans[lvl].push_back(node->val);
            if(node->left != NULL) q.push({node->left, lvl+1});
            if(node->right != NULL) q.push({node->right, lvl+1});
        }
        return ans;
        
    }
};