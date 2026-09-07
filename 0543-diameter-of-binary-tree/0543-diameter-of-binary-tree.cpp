/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dia;
    int Level(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = Level(root->left);
        int r = Level(root->right);
        if(l+r > dia) dia = l+r;
        return 1 + max(l, r);
    };
    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        Level(root);
        return dia;
    }
};