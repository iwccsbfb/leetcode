class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int idx = 0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] != 0) {
				nums[idx++] = nums[i];
			}
		}
		for(int i=idx; i<nums.size(); i++) 
			nums[i] = 0;
	}
	
    void moveZeroes2(vector<int>& nums) {
        int i=-1, j=0;
        
        for(;j<nums.size(); j++){
            if(nums[j] != 0) 
                std::swap(nums[++i], nums[j]);
        }
        
    }
};