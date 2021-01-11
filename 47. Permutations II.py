from typing import List
import copy 
from collections import Counter

class Solution:
    def helper(self, nums):
        if len(nums) <= 1:
            return {tuple(nums)}
        sub = self.helper(nums[:-1])
        res = set()
        for l in sub:
            for j in range(len(l)+1):
                t = l[:j] + (nums[-1],) + l[j:]
                print (t)
                res.add(t)
        return res
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = self.helper(nums)
        return [list(i) for i in res]

    ################### ethod2: use backtrack ####################
    

    def permuteUnique2(self, nums: List[int]) -> List[List[int]]:
        from collections import Counter
        data = Counter(nums)
        res = []
        
        def recurse( data, status ):
            if len(status) == len(nums):
                res.append( status.copy() )
                return 
            for k in data.keys():
                if data[k]:
                    status.append(k)
                    data[k] -= 1

                    recurse(data, status)

                    status.pop()
                    data[k] += 1
                
        recurse(data, [] )
        return res



print(Solution().permuteUnique2( [1,1,2] ))

