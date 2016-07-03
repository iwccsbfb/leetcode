class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    auto nei = findNeighbors(grid, visited, i, j);
                    while(!nei.empty()){
                        vector< pair<int,int> > nei2;
                        for(auto &p: nei){
                            for(auto &p2: findNeighbors(grid, visited, p.first, p.second))
                                nei2.push_back(p2);
                        }
                        nei = std::move(nei2);
                    }
                }
                visited[i][j] = true;
            }
        }
        return cnt;
    }
private: 
    vector< pair<int,int> > findNeighbors(vector<vector<char>>& grid, vector<vector<bool>> &visited,
                                            int i, int j){
        int m = grid.size(), n = grid[0].size();
        vector<  pair<int,int> > res;
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j] == '1') {
            visited[i-1][j] = true;
            res.push_back(std::make_pair(i-1,j));
        }
        if(i+1<m && !visited[i+1][j] && grid[i+1][j] == '1') {
            visited[i+1][j] = true;
            res.push_back(std::make_pair(i+1,j));
        }
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == '1') {
            visited[i][j-1] = true;
            res.push_back(std::make_pair(i,j-1));
        }
        if(j+1<n && !visited[i][j+1] && grid[i][j+1] == '1') {
            visited[i][j+1] = true;
            res.push_back(std::make_pair(i,j+1));
        }
        return res;
    }
};