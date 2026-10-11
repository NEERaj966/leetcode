class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailId;

        // Merge accounts that share an email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (emailId.find(mail) == emailId.end()) {
                    emailId[mail] = i;
                } else {
                    unite(emailId[mail], i);
                }
            }
        }

        // Collect emails by their root account
        vector<vector<string>> merged(n);

        for (auto& it : emailId) {
            string mail = it.first;
            int root = find(it.second);

            merged[root].push_back(mail);
        }

        vector<vector<string>> ans;

        // Build final output
        for (int i = 0; i < n; i++) {
            if (merged[i].empty())
                continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string& mail : merged[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};