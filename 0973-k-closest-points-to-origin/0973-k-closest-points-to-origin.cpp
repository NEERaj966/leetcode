class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        vector<pair<double ,int>> dist(points.size());

        for(int i = 0 ; i < points.size(); i++){
            dist[i].first = sqrt(points[i][0]*points[i][0] +points[i][1]*points[i][1]);
            dist[i].second = i;
        }

        sort(dist.begin() , dist.end());

        // for(auto val : dist){
        //     cout << val.first << " " << val.second << endl;
        // }

        for(int i = 0 ; i< k ; i++){
            ans.push_back(points[dist[i].second]);
        }

        return ans;

        
    }
};