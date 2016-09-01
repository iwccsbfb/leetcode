#include <algorithms>
// f(n,k,target) = f(n-1, k-1, target-nums[n]) + f(n-1,k, target)
//             = 1/0    n == k
//             =    nums[n] < target ? 1: 0        k == 0   
class Solution {
public:
//ERROR: only when this is still remainer of target, we have the option to not select anything.
    int threeSumSmaller2(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        return f(nums, nums.size(), 3, target);
    }
    
    int f(vector<int> &nums, int n, int k, int target) {
        
        if(n < k) return 0;
        if(k == 0) return 0 < target ? 1 : 0;
        if(n == k) return f(nums, n-1, k-1, target - nums[n-1]);
        return f(nums, n-1, k-1, target-nums[n-1]) + f(nums, n-1,k, target);
    }
    
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<n; i++) {
            int tar = target - nums[i];
            int p1 = i+1, p2 = n-1;
            while(p1 < p2) {
                if(nums[p1] + nums[p2] < tar) {
                    // HERE: add p2-p1, then increase p1
                    res += p2 - p1;
                    p1 ++;
                } else p2--;
            }
        }
        return res;
    }
};








