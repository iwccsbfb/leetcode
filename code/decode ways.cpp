class Solution {
    int helper(string s, int start){
        int res = 0, sz = s.size();
        if(start >= sz) return 1;
        
        for(int i=start; i<sz; i++){
            if('3' <= s[i] || (s[i]=='2' && (i==sz-1 || '7'<=s[i+1])) )
                return helper(s, i+1);
            else if( ((s[i]=='1' || s[i]=='2') && (i==sz-1 || s[i+1]=='0')) )
                return helper(s, i+2);
            else 
                return helper(s, i+1) + helper(s, i+2);
        }
    }
public:
    int numDecodings(string s) {
        int sz = s.size();
        if(sz == 0) return 0;
        vector<int>f(sz+1, -1);
        f[sz-1] = f[sz] = 1;
        if(s[sz-1] == '0') f[sz-1] = 0;
        for(int i=sz-2; i>=0; i--){
            if(('3' <= s[i] || (s[i]=='2' && '7'<=s[i+1])))
                f[i] = f[i+1];
            else if(((s[i]=='1' || s[i]=='2') && s[i+1]=='0')){
                f[i] = f[i+2];
            }else if(s[i] == '0')
                f[i] = 0;
            else
                f[i] = f[i+1] + f[i+2];
        }
        return f[0];
    }
};