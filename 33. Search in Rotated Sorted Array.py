from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        s, e = 0, len(nums)-1
        while s < e-1:
            idx = (s+e)//2
            if nums[idx] == target:
                return idx
            if nums[idx] > nums[0]: # rotate point is right of mid; or there is no rotate point
                if nums[s] <= target < nums[idx]:
                    e = idx - 1
                else:
                    s = idx + 1
            else:   # rotate point is left of mid
                if nums[idx] < target <= nums[e]:
                    s = idx + 1
                else:
                    e = idx - 1
        if nums[s] == target: return s
        if nums[e] == target: return e
        return -1
        
                    