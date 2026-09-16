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

    void dfs(TreeNode* root, int target,
             vector<int>& path,
             vector<vector<int>>& ans) {

        // No node
        if (root == nullptr)
            return;

        // Add current node
        path.push_back(root->val);

        // If leaf and sum becomes 0
        if (root->left == nullptr &&
            root->right == nullptr &&
            target == root->val) {

            ans.push_back(path);
        }

        // Go left
        dfs(root->left, target - root->val, path, ans);

        // Go right
        dfs(root->right, target - root->val, path, ans);

        // BACKTRACK
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};