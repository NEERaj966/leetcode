class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m , false));
        queue<pair<int, int>>q;
        vector<vector<int>> ans;

        q.push({sr , sc});

        vis[sr][sc] = true;
        int s = image[sr][sc];
        image[sr][sc] = color;

        while(q.size() > 0){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i-1 >=0 && image[i-1][j] == s && !vis[i-1][j]){ // left
                image[i-1][j] = color;
                q.push({i-1 , j});
                vis[i-1][j] = true;
            }

            if(i+1 < n && image[i+1][j] == s && !vis[i+1][j]){ //right
                q.push({i+1 , j});
                vis[i+1][j] = true;
                image[i+1][j] = color;
            }

            if(j-1 >=0 && image[i][j-1] == s && !vis[i][j-1]){ //top
                q.push({i , j-1});
                vis[i][j-1] = true;
                image[i][j-1] = color;
            }

            if(j+1 >=0 && image[i][j+1] == s && !vis[i][j+1]){ // bottom
                q.push({i , j+1});
                vis[i][j+1] = true;
                image[i][j+1] = color;
            }
        }


        for(int i = 0 ; i < n ; i++){
            vector<int> temp = {};
            for(int j = 0 ; j < m ; j++){
                temp.push_back(image[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};