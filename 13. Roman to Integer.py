

class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':             1,
            'V':             5,
            'X':             10,
            'L':             50,
            'C':            100,
            'D':            500,
            'M':            1000 }
        l = [d[i] for i in s]
        res = l[-1]
        for idx, val in enumerate(l[:-1]):
            if val < l[idx+1]:
                res -= val
            else:
                res += val
        return res



