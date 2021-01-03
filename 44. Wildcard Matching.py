# need to archive result. Otherwise, time limit won't be met

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        d = {}
        def dp(s: str, p: str) -> bool:
            if (len(s), len(p)) in d:
                return d[len(s), len(p)]
            #nonlocal count
            # count = count +  1
            if len(p) == 0:
                res = len(s) == 0
            elif p[0] == '*':
                res = (len(s) != 0 and dp(s[1:], p)) or\
                    dp(s, p[1:])
            else:
                res = len(s) != 0 and p[0] in {'?', s[0]} and \
                    dp(s[1:], p[1:])
            d[len(s), len(p)] = res
            return res
        res = dp(s, p)
        return res

assert(Solution().isMatch("aa", "*") == True)
assert(Solution().isMatch("aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab", "*ab***ba**b*b*aaab*b") == True)

