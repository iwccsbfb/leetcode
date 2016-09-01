class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1, 0);
        int s = length,  e = -1;
        for(auto &tup : updates) {
            res[tup[0]] += tup[2];
            res[tup[1]+1] -= tup[2];
            s = min(s, tup[0]);
            e = max(e, tup[1]+1);
        }
        for(int i=s+1; i<=e; i++) {
            res[i] += res[i-1];
        }
        res.pop_back();
        return res;
    }
};



