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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    };
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr ) return (p==q);
        if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && p->val == q->val) return true;
        else return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        // return isSameTree(invertTree(root->left),root->right);
        invertTree(root->right);
        bool ans = isSameTree(root->left,root->right);
        invertTree(root->right);
        return ans;

    }
};