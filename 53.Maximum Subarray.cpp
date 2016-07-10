class Solution {
public:
// divide and conquer
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return maxSubArray(nums, 0, nums.size()-1);
    }
    int maxSubArray(vector<int> &nums, int s, int e) {
        if(s > e) return INT_MIN;
        if(s == e) return nums[s];
        int mid = (s+e)/2;
        int left_res = maxSubArray(nums, s, mid-1);
        int right_res = maxSubArray(nums, mid+1, e);
        // 需要初始化为0，而不是INT_MIN!!
        int left_max = 0, right_max = 0;
        int sum = 0;
        for(int i=mid-1; i>=s; i--) {
            sum += nums[i];
            left_max = max(left_max, sum);
        }
        sum = 0;
        for(int i=mid+1; i<=e; i++) {
            sum += nums[i];
            right_max = max(right_max, sum);
        }
        return max(max(left_res, right_res), nums[mid]+left_max+right_max);
    }
	
    // O(N) time complexity
    int maxSubArray2(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            int prev = (i==0? 0 : arr[i-1]);
            if(prev <= 0) arr[i] = nums[i];
            else arr[i] = prev + nums[i];
        }
        int res = arr[0];
        for(auto &i : arr) res = max(res, i);
        return res;
    }
};