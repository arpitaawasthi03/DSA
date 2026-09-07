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
// bool isBalance = true;
//     int Level(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         int l = Level(root->left);
//         int r = Level(root->right);
//         if ((abs(l-r))>1) isBalance = false;
//         return 1+ max(l,r);
//     };
//     bool isBalanced(TreeNode* root) {
//         Level(root);
//         return (isBalance);
//     }

    int Level(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1+ max(Level(root->left),Level(root->right));
    };
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int l = Level(root->left);
        int r = Level(root->right);
        if(abs(l-r)>1) return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};