from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        i = len(nums) - 1
        while i > 1:
            target = -nums[i]
            j = 0
            k = i-1
            while j<k:
                temp = nums[j] + nums[k]
                if temp < target:
                    j += 1
                elif temp > target:
                    k -= 1
                else:
                    res.append([nums[j], nums[k], nums[i]])
                    j += 1
                    k -= 1
                # remove duplicates
                while j >= 1 and j < k and nums[j] == nums[j-1]:
                    j += 1
                while k>j and k<i-1 and nums[k] == nums[k+1]:
                    k -= 1
            i -= 1
            while i > 1 and i < len(nums)-1 and nums[i] == nums[i+1]:
                i -= 1
           
        return res #list(set(res))
    
    
res = Solution().threeSum([-1,0,1,2,-1,-4])
print (res)
    
    

