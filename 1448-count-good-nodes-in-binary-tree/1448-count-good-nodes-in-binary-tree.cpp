class Solution {
public:
    int solve(TreeNode* root, int max_so_far) {
        if (root == nullptr) return 0;
        int good = 0;
        if(root->val >= max_so_far){
            good++;
            max_so_far = root->val;
        }
        int left = solve(root->left,max_so_far);
        int right = solve(root->right,max_so_far);
        return good+left+right;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};