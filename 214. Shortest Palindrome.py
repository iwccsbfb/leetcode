# there is a more efficient solution
    # Manacher's Algo for palindrome 
    # Fast FFT
# check https://leetcode.com/problems/shortest-palindrome/


class Solution:
    def shortestPalindrome(self, s: str) -> str:
        def isPalindrome(s):
            return s[::-1] == s
            #for i in range(len(s)//2):
            #    if s[i] != s[len(s)-1-i]:
            #        return False
            #return True
        
        if len(s) == 0:
            return ""
        for i in range(len(s), 0, -1):
            if isPalindrome(s[:i]):
                return s[i:][::-1] + s