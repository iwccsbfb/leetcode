class Solution {
public:
// ERROR: 加一，减一，判断越界，出过好几个错误
// 有简单一点的，不需要递归的方法；
// http://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;
        int h = matrix.size(), w = matrix[0].size();
        res.reserve(h*w);
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        helper(matrix, visited, 0, 0, Left2Right, res);
        return res;
    }
private:
    enum Direction {
        Left2Right = 0, Top2Down, Right2Left, Down2Top
    };
    void helper(vector<vector<int>>& matrix, vector<vector<bool>> &visited,
                int s_i, int s_j, Direction dir, vector<int> &res) {
        int h = matrix.size(), w = matrix[0].size();
        int i = s_i, j = s_j;
        if(i < 0 || j < 0 || i >= h || j >= w || visited[i][j]) return;
        
        switch(dir) {
            case Left2Right:
            for(; j<w; j++) 
                if(!helper_one_element(matrix, visited, i, j, res) ) {
                    break;
                }
            j--;
            helper(matrix, visited, i + 1, j, Top2Down, res);
            break;
            
            case Top2Down:
            for(; i<h; i++) 
                if(!helper_one_element(matrix, visited, i, j, res) ){
                    break;
                }
            i--;
            helper(matrix, visited, i, j - 1, Right2Left, res);
            break;
            
            case Right2Left:
            for(; j>=0; j--) 
                if(!helper_one_element(matrix, visited, i, j, res) ) {
                    break;
                }
            j++;
            helper(matrix, visited, i - 1, j, Down2Top, res);
            break;
            
            case Down2Top:
            for(; i>=0; i--)
                if(!helper_one_element(matrix, visited, i, j, res) ) {
                    break;
                }
            i++;
            helper(matrix, visited, i, j + 1, Left2Right, res);
            break;
        }
    }
    
    inline bool helper_one_element(vector<vector<int>>& matrix, vector<vector<bool>> &visited,
                    int i, int j, vector<int> &res) {
        if(visited[i][j]) return false;
        visited[i][j] = true;
        res.push_back(matrix[i][j]);
        return true;
    }
};