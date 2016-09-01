class Solution {
	// �����Ҫ����û��ƫ�Ƶ������search in rotated sorted array����
public:
    //��������ǿ�
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
    int findMin(vector<int>& nums, int l, int r) {
        if(l == r) return nums[l];
        if(l == r-1) return min(nums[l], nums[r]);
        // ���û��ƫ��
        if(nums[l] < nums[r]) return nums[l];
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[l]) return findMin(nums, mid, r);
        return findMin(nums, 0, mid);
    }
};