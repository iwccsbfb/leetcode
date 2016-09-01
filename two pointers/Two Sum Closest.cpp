class Solution {
public:
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
    int twoSumCloset(vector<int>& nums, int target) {
        if(nums.empty()) return INT_MAX;
        sort(nums.begin(), nums.end());
        
        int p1 = 0, p2 = nums.size()-1;
        int res = INT_MAX;
        // int diff_smaller = INT_MAX, diff_bigger = INT_MAX;
        while(p1<p2) {
            int sum = nums[p1] + nums[p2];
            if(sum < target)
                p1++;
            else if(sum > target) 
                p2--;
            else return 0;
            res = min(res, abs(target-sum));
        }
        return res;
    }
};