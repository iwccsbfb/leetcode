from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]
        if len(nums) <= 2: return min(nums)
        s = 0
        e = len(nums) - 1
        while s < e-1:
            mid_idx = (s+e) // 2
            if nums[mid_idx] > nums[0]:
                s = mid_idx 
            else:
                e = mid_idx 
        return min(nums[s], nums[e])
    
        
    def findMin1(self, nums: List[int]) -> int:
        # assume nums cannot be empty
        if len(nums) <= 3: return min(nums)
        mid_idx = len(nums) // 2
        mid = nums[mid_idx]
        if nums[mid_idx-1] > mid and mid < nums[mid_idx+1]:
            return mid
        if nums[mid_idx-1] < mid and mid > nums[mid_idx+1]:
            return nums[mid_idx+1]
        
        if nums[0] < mid and mid > nums[-1]:
            return self.findMin(nums[mid_idx+1:])
        if nums[0] > mid and mid < nums[-1]:
            return self.findMin(nums[:mid_idx])
        if nums[0] < mid < nums[-1]:
            return nums[0]
        
        
    def findMin2(self, nums: List[int]) -> int:
        # assume nums cannot be empty
        if len(nums) <= 3: return min(nums)
        mid_idx = len(nums) // 2
        mid = nums[mid_idx]
        
        if nums[0] < mid and mid > nums[-1]:
            return self.findMin(nums[mid_idx:]) # this line is different
        if nums[0] > mid and mid < nums[-1]:
            return self.findMin(nums[:mid_idx+1]) # this line is different
        if nums[0] < mid < nums[-1]:
            return nums[0]
        