class Solution {
public:

    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

  

    string dfs(TreeNode* root) {

        if (root == NULL)
            return "#";

        string key = to_string(root->val) + "," +
                     (dfs(root->left)) + "," +
                     (dfs(root->right));


       mp[key]++;


        if (mp[key] == 2) {
            ans.push_back(root);
        }

        return key;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        dfs(root);

        return ans;
    }
};