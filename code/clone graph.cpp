/**
first clone nodes, then clone edges;
DFS and BFS
Refer:
http://bangbingsyb.blogspot.com/2014/11/leetcode-clone-graph.html

 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
struct myHasher{
    size_t operator()(UndirectedGraphNode* const &node) const{
        int val = reinterpret_cast<long long>(node);
        if(node != nullptr) 
            val += node->label;
        return val;
    }
};
class Solution {
    void dfs(UndirectedGraphNode *p, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*, myHasher> &map,
                unordered_set<UndirectedGraphNode*, myHasher> &visited){
        visited.insert(p);
		map[p] = new UndirectedGraphNode(p->label);
        for(auto &i : p->neighbors){
            if(visited.find(i) == visited.end()) {
                dfs(i, map, visited);
            }
        }
    }
    
    void dfs2(UndirectedGraphNode *p, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*, myHasher> &map,  unordered_set<UndirectedGraphNode*, myHasher> &visited){
        for(auto &i : p->neighbors){
            map[p]->neighbors.push_back(map[i]);
        }
        visited.insert(p);
        
        for(auto &i : p->neighbors){
            if(visited.find(i) == visited.end()) 
                dfs2(i, map, visited);
        }
    }
    
    // build up all the nodes
    void bfs1(UndirectedGraphNode *p, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*, myHasher> &map,
                unordered_set<UndirectedGraphNode*, myHasher> &visited){
        vector<UndirectedGraphNode *> v1 = p->neighbors, v2;
        while(!v1.empty()){
            for(auto &i : v1){
                if(visited.find(i) == visited.end()) {
                    visited.insert(i);
                    auto p = new UndirectedGraphNode(i->label);
                    map[i] = p;
                    
                    v2.push_back(i);
                }
            }
            v1 = std::move(v2);
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*, myHasher> map;
        unordered_set<UndirectedGraphNode*, myHasher> visited;
        auto p = node;
        dfs(p, map, visited);
        visited.clear();
        dfs2(p, map, visited);
        return map[node];
    }
};