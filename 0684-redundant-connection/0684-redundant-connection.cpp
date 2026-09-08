class Solution {
public:
    vector<int>parent;
    int find(int a){
        if(parent[a] == a) return a;

       return parent[a] = find(parent[a]);
    }

    int unite(int a , int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        parent[pa] = pb;
        return true;
    }
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
       parent.resize(n+1);

       for(int i = 1 ; i <= n ; i++){
         parent[i] = i;
       }

       for(auto& edge : edges){
        int a = edge[0];
        int b = edge[1];

        if(!unite(a , b)) return edge;
       }

       return {};
    }
};