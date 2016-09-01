/*
	  0
	 / \ 
	 1  2
	/ \ /
   3   4
	vector<pair<int, int>> v{ make_pair(0,1),make_pair(0,2),make_pair(2,3),make_pair(2,4) };
	Solution().validTree(5, v);
Output: false
Expected: true
*/

class Solution {
public:
// union find 
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i] = i;
        for(auto &p: edges) {
            int r1 = root(v, p.first), r2 = root(v, p.second);
            if(r1 != r2) v[r1] = r2;
            else return false;
        }
		// 不需要继续遍历数组
        return edges.size() == n-1;
        
        int r1 = root(v, v[0]);
        v[0] = r1;
        for(int i=1; i<v.size(); i++)
            if( (v[i] = root(v, v[i])) != r1) 
                return false;
        return true;
    }
    
    int root(vector<int> &v, int val) {
        while(v[val] != val) val = v[val];
        return val;
    }
    
    bool validTree1(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        vector< vector<int>> G(n); // use adjacency lists
        for(auto &p: edges) {
            G[p.first].push_back(p.second);
            G[p.second].push_back(p.first);
        }
        
        vector<bool> acc(n, false);
        acc[0] = true;
        
        vector<int> v1{0}, v2;
        while(!v1.empty()) {
            for(auto i: v1) {
                for(auto j : G[i])
                {
                    if(j == i) continue;
                    if(acc[j]) return false;
                    acc[j] = true;
                    v2.push_back(j);
                }
            }
            v1 = std::move(v2);
        }
        for(auto i: acc)
            if(!i) return false;
        return true;
    }
    
//在这个写法里，path不包含cur node; 
    bool validTree2(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        vector< vector<int>> G(n); // use adjacency lists
        for(auto &p: edges) {
            G[p.first].push_back(p.second);
            G[p.second].push_back(p.first);
        }
        vector<bool>acc(n, false); // accessed or not
        acc[0] = true;
        vector<int> path = {};
        if(!dfs(G, 0, path, acc)) return false;
        for(auto i: acc)
            if(!i) return false;
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &G, int cur, vector<int> &path, vector<bool> &acc) {
        acc[cur] = true;
        for(auto &nb: G[cur]) {
            if(!path.empty() && nb == path.back()) continue;
            if(exist(path, nb)) return false;
            
            path.push_back(cur);
            if(!dfs(G, nb, path, acc)) return false;
            path.pop_back();
        }
        return true;
    }
    inline bool exist(vector<int> &v, int ele) {
        for(auto &i: v) if(i == ele) return true;
        return false;
    }
};