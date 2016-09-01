

class Solution {
public:
	// 1. Kadane's algorithm
	// 2: prefix sum; 
	// 3. divide and conquer; O(N^2)
	// max_ending_here can be empty array
	// but max_so_far cannot be empty array
    int maxSubArray(vector<int> nums) {
		int max_ending_here = 0, max_so_far = INT_MIN;
		for(int i=0; i<nums.size(); i++) {
			int num = max_ending_here+nums[i];
			if(num > 0) {
				max_ending_here = num;
				max_so_far = max(max_so_far, max_ending_here);
			} else {
				max_ending_here = 0;
				max_so_far = max(max_so_far, nums[i]);
			}
		}
		return max_so_far;
	}
	
    // 2: prefix sum; v[i] = sum - minSum
    /*int maxSubArray2(vector<int> nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int res = nums[0];
        int sum = nums[0];
        int minSum = min(0,sum);
        for(int i=1; i<sz; i++ ) {
            sum += nums[i];
            res = max(sum - minSum, res);
            minSum = min(minSum, sum);
        }
        return res;
    }*/
    int maxSubArray2(vector<int> nums) {
        // prefix对应的数组不为空；
        // min_sum对应的数组可以为空
        int prefix = 0, min_sum = 0, res = nums[0];
        for(int i=0; i<nums.size(); i++) {
            prefix += nums[i];
            res = max(res, prefix - min_sum);
            min_sum = min(min_sum, prefix);
        }
        return res;
    }
    
    int maxSubArray3(vector<int> nums) {
        // DP： v的大小设为sz, not sz+1
        int sz = nums.size();
        vector<int> v(sz, 0);
        v[0] = nums[0];
        for(int i=1; i<sz; i++) {
            v[i] = max(v[i-1], 0)+ nums[i];
        }
        //cout<<v[0]<<' '<<sz<<endl;
        int res = v[0];
        for(int i=1; i<sz; i++)
            if(v[i]> res) res = v[i];
        return res;
    }
};
