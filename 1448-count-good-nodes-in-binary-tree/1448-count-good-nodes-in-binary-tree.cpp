class Solution {
public:
    int count = 0;

    void helper(TreeNode* root, int maxel) {
        if (!root) return;

        // If current node is good
        if (root->val >= maxel) {
            count++;
        }

        // Update maximum value
        maxel = max(maxel, root->val);

        helper(root->left, maxel);
        helper(root->right, maxel);
    }

    int goodNodes(TreeNode* root) {
        helper(root, root->val);
        return count;
    }
};