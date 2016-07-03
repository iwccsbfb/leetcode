class Solution {

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0) return res;
        // reflect the solution to get sol for i from (n+1)/2+1 to n
        for(int i=1; i<=(n+1)/2; i++){
            vector<int> sol{i};
            solve(res, sol, 1, n);
        }
        return res;
    }

private:
    void solve(vector<vector<string>> &res, vector<int> &sol, int cur_step, int n){
        if(cur_step == n){
            {
                vector<string> sol2;
                for(int i=0; i<n; i++){
                    string str(n, '.'); 
                    str[sol[i]-1] = 'Q';
                    sol2.push_back(str);
                }
                res.push_back(sol2);
            }
            int first_step = sol.front();
            // add the reflected solution
            if(n+1 - first_step != first_step){
                vector<string> sol3;
                for(int i=0; i<n; i++){
                    string str(n, '.'); 
                    str[n - sol[i]] = 'Q';
                    sol3.push_back(str);
                }
                res.push_back(sol3);
            }
            return;
        }
        int last_step = sol.back();
        // i is current step
        for(int i=1; i<=n; i++){
            if(abs(i-last_step) <= 1) continue;
            if(is_valid(sol, i)){
                sol.push_back(i);
                solve(res, sol, cur_step+1, n);
                sol.pop_back();
            }
        }
    }
    
    bool is_valid(vector<int> &sol, int next_step){
        int sz = sol.size();
        for(int i=0; i<sz; i++){
            if(sol[i] == next_step || abs(next_step-sol[i])==abs(sz-i) )
                return false;
        }
        return true;
    }
};