// 返回的是i，还是i-1，还是i+1；这个要区分好
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j<n; j++) {
            if(nums[j] != val)
                nums[i++] = nums[j];
        }
        return i;
    }
};