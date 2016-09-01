class Solution {
public:
    /**
     * 1. Kadane's algorithm
     * 2. prefix sum; 
     */
    int minSubArray1(vector<int> nums) {
        int min_ending_here = 0, min_so_far = nums[0];
        for(int i=0; i<nums.size(); i++) {
            int num = min_ending_here + nums[i];
            if(num > 0) {
                min_ending_here = 0;
                min_so_far = min(min_so_far, nums[i]);
            } else {
                min_ending_here = num;
                min_so_far = min(min_so_far, min_ending_here);
            }
            /*下面这种写法并不行；因为num>0时，第二个式子不成立
            min_ending_here = min(0, min_ending_here + nums[i]);
            min_so_far = min(min_so_far, 
                              min(min_ending_here, nums[i]) );
                              */
        }
        return min_so_far;
    }
    // 错误:对于min_subarray,要用max_sum, 而不是min_sum
    int minSubArray2(vector<int> nums) {
        int sum = 0, max_sum = 0, res = nums[0];
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            res = min(res, sum - max_sum);
            max_sum = max(max_sum, sum);
        }
        return res;
    }
    
    int minSubArray(vector<int> nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = nums[0];
        for(int i=1; i<n; i++)
            arr[i] = nums[i] + min(0, arr[i-1]);
        int res = INT_MAX;
        for(auto i: arr) res = min(i, res);
        return res;
    }
};
