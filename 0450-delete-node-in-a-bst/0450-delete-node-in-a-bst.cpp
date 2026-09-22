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
    TreeNode* maxNode(TreeNode* root) {

        while(root->right != nullptr){
            root = root->right;
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int k) {

        if(root == nullptr) return nullptr;

        if(root->val == k){
            // leaf Node
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }
            // one child
            else if(root->left == nullptr ){
                return root->right;
            }
            else if(root->right == nullptr ){
                return root->left;
            }
            // two childs
            else if(root->left != nullptr && root->right != nullptr){

                TreeNode* temp = maxNode(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }
        if(root->val > k){
            root->left = deleteNode(root->left,k);
        }else if(root->val < k){
            root->right = deleteNode(root->right,k);
        }
        return root;
    }
};