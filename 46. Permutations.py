from typing import List

class Solution:

    ############# recursion algo #########
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 1:
            return [nums]
        sub = self.permute(nums[:-1])
        res = []
        for l in sub:
            for j in range(len(l)+1):
                res.append(l[:j] + [nums[-1]] + l[j:])
        return res


    ############# backtrack algo ###########
    def permute2(self, nums: List[int]) -> List[List[int]]:
        res = []
        value = []
        def backtrack(nums, value):
            import copy
            if not nums:
                res.append( copy.copy(value) )
                return
            for i in nums:
                value.append(i)
                backtrack(nums-{i}, value)
                value.pop()
            
        backtrack(set(nums), value)
        return res



print ( Solution().permute2( [1,2,3]) )