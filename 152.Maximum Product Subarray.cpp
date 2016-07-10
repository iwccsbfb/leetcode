class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> pos_max(n), neg_max(n);
        int res = pos_max[0] = neg_max[0] = nums[0];

        for(int i=1; i<n; i++) {
            if(nums[i] >= 0) {
                pos_max[i] = max(pos_max[i-1]*nums[i], nums[i]);
                neg_max[i] = neg_max[i-1] * nums[i];
            }
            else {
                pos_max[i] = neg_max[i-1] * nums[i];
                neg_max[i] = min(pos_max[i-1] * nums[i], nums[i]);
            } 
            res = max(res, pos_max[i]);
        }
        return res;
    }
};