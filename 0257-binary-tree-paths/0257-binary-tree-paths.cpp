class Solution {
public:
    int sum = 0;
    void path(TreeNode* root, string s, vector<string>& ans) {
        if (root == nullptr) return;

        s += to_string(root->val);

        cout << s << "  ";

        // Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(s);
            return;
        }

        s += "->";

        path(root->left, s, ans);
        path(root->right, s, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root, "", ans);
        return ans;
    }
};