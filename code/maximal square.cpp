class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty()) return res;
        int sz1 = matrix.size(), sz2 = matrix[0].size();
        for(int i=0; i<sz1-res; i++){
            for(int j=0; j<sz2-res; j++){
                if(matrix[i][j] == '1'){
                    int cnt = 1;
                    for(; i+cnt<sz1 && j+cnt<sz2 ;cnt++) 
                    {
                        bool flag = true;
                        for(int k=0;k<=cnt; k++){
                            if(matrix[i+cnt][j+k] != '1'){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag) break;
                        for(int k=0;k<cnt; k++){
                            if(matrix[i+k][j+cnt] != '1'){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res*res;
    }
    
};