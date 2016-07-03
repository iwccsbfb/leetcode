/*
topological sort
1. recursion: choose a sink vertex v (out degree is zero), recurse on G-{v} and E-{all edge end at v}
erase sink vertex one by one; if all vertices are removed, then true; 
a: unordered_set is quicker in insert and erase than set; 
b: need to have an array to record whether a vertex has been removed. (otherwise, could have infinite loop)

2. DFS: current_node records the vertex No. O(m+n)
DFS should access all the neighbors; not just one;
*/

// also do the recursion way
class Solution {
    bool dfs(vector< vector<int> > &graph, vector<int> &visited, int &cnt, int node) {
        // bool done = false;
        visited[node] = -1;
        // access all the neighbors
        for(auto &nei: graph[node]){
            if(visited[nei] == 0){
                //done = true;
                if(!dfs(graph, visited, cnt, nei))
                    return false;
            }
			// return to same point in current path;
            if(visited[nei] == -1)
                return false;
        }
        visited[node] = visited.size() - cnt;
        cnt++;
        return true;
    }
    
public:

	vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
        // convert to adjacency lists
        vector< vector<int> > graph(n, vector<int>{});
        for(auto &i: prerequisites){
            graph[i.second].push_back(i.first);
        }
        // 0: not visited; 1: visited in this round
        vector<int> visited(n, 0);
        // count of how many vertices that are visited
        int cnt = 0; 
        for(int i=0; i<n; i++){
            if(visited[i] == 0 && !dfs(graph, visited, cnt, i))
                return vector<int>();
            if(cnt == n) break;
        }
        vector<int>res(n);
        for(int i=0; i<n; i++)
            res[visited[i]-1] = i;
        return res;
    }
	
    bool canFinish(int n, vector<pair<int, int>>& prerequisites) {
        // convert to adjacency lists
        vector< vector<int> > graph(n, vector<int>{});
        for(auto &i: prerequisites){
            graph[i.second].push_back(i.first);
        }
        // 0: not visited; non-zero: the topological order;
        vector<int> visited(n, 0);
        // count of how many vertices that are visited
        int cnt = 0; 
        for(int i=0; i<n; i++){
            if(visited[i] == 0 && !dfs(graph, visited, cnt, i))
                return false;
            if(cnt == n) break;
        }
        return true;
    }
	
    // erase sink vertex one by one
    bool canFinish2(int n, vector<pair<int, int>>& prerequisites) {
        // convert to adjacency lists
        // out: vertices that go out from this vertex; in: vertices that go into this vertex
        vector<unordered_set<int>> out(n), in(n);
        for(auto &i: prerequisites){
            out[i.second].insert(i.first);
            in[i.first].insert(i.second);
        }
        vector<bool>deleted(n, false);
        int cnt = 0;
        while(cnt != n) {
            int old_cnt = cnt;
            for(int i=0; i<n; i++) {
                if(out[i].size() == 0 && !deleted[i]){
                    deleted[i] = true;
                    cnt++;
                    for(auto &prev: in[i])
                        out[prev].erase(i);
                }
            }
            if(cnt == old_cnt) 
                return false;
        }
        return true;
    }
	
};