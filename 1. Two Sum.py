class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tuplist = zip(nums, range(len(nums)))
        tuplist = sorted(tuplist)
        i = 0
        j = len(tuplist) - 1
        while i < j:
            temp = tuplist[i][0] + tuplist[j][0]
            if temp < target:
                i += 1
            elif temp > target:
                j -= 1
            else:
                return [tuplist[i][1], tuplist[j][1]]
