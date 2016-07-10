class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if(numRows == 0) return res;
        res[0] = {1};
        if(numRows == 1) return res;
        res[1] = {1,1};
        if(numRows == 2) return res;
        
        for(int i = 2; i<numRows; i++) {
            vector<int> row(i+1), &before = res[i-1];
            row[0] = row[i] = 1;
            for(int j = 1; j < i; j++) 
                row[j] = before[j] + before[j-1];
            res[i] = row;
        }
        return res;
    }
};