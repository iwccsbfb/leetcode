class Solution {
	// 这道题要考虑没有偏移的情况；search in rotated sorted array则不用
public:
    //假设数组非空
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    int findMin(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        if(l == r-1) return min(nums[l], nums[r]);
        // 如果没有偏移
        if(nums[l] < nums[r]) return nums[l];
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[l]) return findMin(nums, mid, r);
        return findMin(nums, 0, mid);
    }
};