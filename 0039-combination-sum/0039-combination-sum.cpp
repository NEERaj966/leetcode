class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& ans) {
        
        if (target < 0 && start == candidates.size()) {
            return;
        }

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Try every candidate from start
        for (int i = start; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // We pass i, not i+1
            // because the same number can be used again
            backtrack(candidates, target - candidates[i],
                      i, current, ans);

            // Undo choice (backtracking)
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        backtrack(candidates, target, 0, current, ans);

        return ans;
    }
};