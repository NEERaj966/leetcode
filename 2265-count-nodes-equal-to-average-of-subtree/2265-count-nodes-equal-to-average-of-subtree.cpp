class Solution {
public:

    pair<int, int> rootavg(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = rootavg(root->left);
        pair<int, int> right = rootavg(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val) {
            ans++;
        }

        return {sum, count};
    }

    int ans = 0;

    int averageOfSubtree(TreeNode* root) {
        rootavg(root);
        return ans;
    }
};