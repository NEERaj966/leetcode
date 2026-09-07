class Solution {
public:
    bool isCycle(int src, vector<bool>& visit,
                 vector<vector<int>>& prerequisites, vector<bool>& recPath) {
        visit[src] = true;
        recPath[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if (u == src) {
                if (!visit[v]) {
                    if(isCycle(v, visit, prerequisites, recPath)) return true;
                }else if(recPath[v]) return true;
            }
        }

        recPath[src] = false;
        return false;
    }


    void topoSort(int src, vector<bool>& visit,
                  vector<vector<int>>& prerequisites, stack<int>& st) {
        visit[src] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if (u == src) {
                if (!visit[v]) {
                    topoSort(v, visit, prerequisites, st);
                }
            }
        }

        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visit(numCourses, false);
        stack<int> st;
        vector<bool> recPath(numCourses, false);
        

         for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                if(isCycle(i, visit, prerequisites, recPath)) return {};
            }
        }

        for(int i = 0 ; i < numCourses ; i++){
            visit[i] = false;
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visit[i]) {
                topoSort(i, visit, prerequisites, st);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};