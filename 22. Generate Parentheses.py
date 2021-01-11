class Solution:
    def generateParenthesis(self, n: int):
        ''' could work with recursion - think the reasons
            any paren with n pairs, can remove () to become n-1 pairs
        '''
        if n == 1:
            return [ '()' ]
        sub = self.generateParenthesis(n-1)
        s = set()
        for paren in sub:
            for p1 in range(len(paren)):
                for p2 in range(p1, len(paren)):
                    # insert ( before p1, insert ) before p2
                    item = paren[:p1] + '(' + paren[p1:p2] + ')' + paren[p2:]
                    s.add( item )
            # add () to the end of paren - when p1 is equal to end of list
            s.add(paren + '()')
        return list(s)




class Solution2:
    ''' using depth first search - recursion
    '''

    def helper(self, count, left, right, sol):
        ''' a recursive helper function
        '''
        if count < 0 or left <0  or right <0:
            raise Exception('error')
        if left == 0 and right == 0:
            return [sol]
        if count == 0: # if count is 0, must append '('
            return self.helper(count+1, left-1, right, sol+'(')
        else:
            res = []
            if left != 0: # append '(' at current position
                res += self.helper(count+1, left-1, right, sol+'(')
            if right != 0: # append ')' at current position
                res += self.helper(count-1, left, right-1, sol+')')
            return res

    def generateParenthesis(self, n: int):
        ''' could work with recursion - think the reasons
            any paren with n pairs, can remove () to become n-1 pairs
        '''
        left = right = n
        count = 0 # with a (, count +=1; with a ), count -= 1. count must always be non-negative
        sol = '' # current solution
        return self.helper(count, left, right, sol)


class Solution3:
    ''' a breadth first search
    '''
    def generateParenthesis(self, n):
        import collections
        result, queue = set(), collections.deque([("", n, n)])
        
        while queue:
            """
            s: current string / current solution
            l: number of 'open' parenthesize left to place
            r: number of 'close' parenthesize left to place
            """
            s, l, r = queue.popleft()
            
            if l == 0 and r == 0:
                result.add(s)
                continue
                
            if l >= r:
                queue.append((s+"(", l-1, r))
                continue
                
            if l > 0:
                queue.append((s+"(", l-1, r))
                
            if r > 0:
                queue.append((s+")", l, r-1))
                
        return result    


print (Solution().generateParenthesis(3))
print (Solution2().generateParenthesis(3))
print (Solution3().generateParenthesis(3))