class Solution {
public:

    int helper(TreeNode* root, int maxel) {
        if (!root) return 0;

        int count = 0;

        // Is this node good?
        if (root->val >= maxel) {
            count = 1;
        }

        // Update maximum for children
        maxel = max(maxel, root->val);

        count += helper(root->left, maxel);
        count += helper(root->right, maxel);

        return count;
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        return helper(root, root->val);
    }
};