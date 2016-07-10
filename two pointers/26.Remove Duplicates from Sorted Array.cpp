class Solution {
public:
	//方法1比方法2更符合自己的思维习惯
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] != nums[i]) 
                nums[res++] = nums[i];
        }
        return res;
    }
	
    int removeDuplicates2(vector<int>& nums) {
    	if (nums.empty()) return 0;
    	int res = 0;
    	for (int i = 1; i<nums.size(); i++) {
    		if (nums[i] != nums[i - 1])
    			nums[++res] = nums[i];
    	}
    	return res + 1;
    }
};