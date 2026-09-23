class Solution {
public:

    unordered_map<string, int> mp;
    unordered_map<string, int> freq;

    vector<TreeNode*> ans;

    int id = 1;

    int dfs(TreeNode* root) {

        if (root == NULL)
            return 0;

        string key = to_string(root->val) + "," +
                     to_string(dfs(root->left)) + "," +
                     to_string(dfs(root->right));

        // First time seeing this subtree
        if (mp.find(key) == mp.end()) {
            mp[key] = id++;
        }

        // Count occurrence
        freq[key]++;

        // Add only when it appears for the second time
        if (freq[key] == 2) {
            ans.push_back(root);
        }

        return mp[key];
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        dfs(root);

        return ans;
    }
};