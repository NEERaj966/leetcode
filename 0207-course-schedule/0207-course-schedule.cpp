class Solution {
public:
    bool isCycle(int src , vector<bool>& visit , vector<bool>& recPath , vector<vector<int>>& prerequisites){
        visit[src] = true;
        recPath[src] = true;

        for(int i= 0 ; i < prerequisites.size() ; i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u == src){
                if(!visit[v]){
                    if(isCycle(v , visit , recPath , prerequisites)) return true;
                }else if(recPath[v]) return true;
            }
        }

        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visit(numCourses , false);
        vector<bool> recPath(numCourses , false);

        for(int i = 0 ; i < numCourses ; i++){
            if(isCycle(i , visit , recPath , prerequisites)) return false;
        }

        return true;
    }
};