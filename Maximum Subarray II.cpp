class Solution {
public:
    // O(N) 分割线先从左向右，再从右向左
    // 算left[i]的时候，可以用DP然后再update一遍，也可以用贪心
    int maxTwoSubArrays(vector<int> nums) {
        int sz = nums.size();
        if(sz<=1) return 0;
        // left[i]: max subarray end with index; 
        // right[i]: max subarray start with index;
        // then update left[i] to be max subarray before index i;
        vector<int> left(sz,0), right(sz, 0);
        left[0] = nums[0];
        for(int i=1; i<sz; i++) {
            left[i] = max(nums[i], nums[i]+left[i-1]);
        }
        int moving_max = left[0];
        for(int i=1; i<sz; i++) {
            moving_max = max(moving_max, left[i]);
            left[i] = moving_max;
        }
        
        right.back() = nums.back();
        for(int i=sz-2; i>=0; i--) {
            right[i] = max(nums[i], nums[i]+right[i+1]);
        }
        moving_max = right.back();
        for(int i=sz-2; i>=0; i--) {
            moving_max = max(moving_max, right[i]);
            right[i] = moving_max;
        }
        int sum = left[0] + right[1];
        for(int i=1; i<=sz-2; i++) 
            sum = max(sum, left[i]+right[i+1]);
        return sum;
    }
};
