/*
1. 用两个数组存比当前数字小（或者大）的数字的index； 
空间复杂度： O(2N),时间复杂度：O(N)
mehtod 2. DP
Space complexity O(1), Time complexity: O(N^2)
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        vector<int> f1(sz, -1), f2(sz, -1);
        int min_val = INT_MAX, min_idx = -1;
        for(int i=0; i<sz; i++){
            if(nums[i] > min_val){
                f1[i] = min_idx;
            }else{
                min_val = nums[i];
                min_idx = i;
            }
            
        }
        
        int max_val = INT_MIN, max_idx = -1;
        for(int i=sz-1; i>=0; i--){
            if(nums[i] < max_val){
                f2[i] = max_idx;
            }else{
                max_val = nums[i];
                max_idx = i;
            }
        }
        
        for(int i=0; i<sz; i++)
            if(f1[i] != -1 && f2[i] != -1)
                return true;
        return false;
    }
    
    bool increasingTriplet2(vector<int>& nums) {
        if(nums.size()<=2) return false;
        int sz = nums.size();
        vector<int> f(sz, 1);
        for(int i=0; i<sz; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i] && (f[i] = max(f[i], f[j]+1)) == 3)
                        return true;
            }
        }
        return false;
    }
};