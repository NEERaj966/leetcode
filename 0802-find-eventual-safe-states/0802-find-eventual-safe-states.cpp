class Solution {
public:
    bool DFS(int src , vector<bool>&vis, vector<bool>&recPath , vector<vector<int>>& graph , vector<bool> &check ){
        vis[src] = true;
        recPath[src] = true;

        for(auto edge : graph[src]){

            if(!vis[edge]){
                if(DFS(edge , vis , recPath , graph , check)) return true;
            }else if(recPath[edge]) return true;
        }

        check[src] = true;
        recPath[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n , false);
        vector<bool>recPath(n , false);
        vector<bool> check(n , false);
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                DFS(i  , vis  , recPath , graph , check);
            }
        }

        for(int i = 0 ; i <n ; i++){
            if(check[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};