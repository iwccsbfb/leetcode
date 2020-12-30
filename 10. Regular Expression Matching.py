# implemented finite state machine below
# Leetcode has more concise dp or recursion algorithms:
# https://leetcode.com/problems/regular-expression-matching/solution/


# pattern: ma*abc
# state graph:  s0 -m-> s1 --> s2 -a-> s3 -b-> s4 -c-> s5
# here s1 to s2 is autoTransit; s2 has another loop: s2 -a-> s2

class State:
    def __init__(self ):
        self.autoTransit = False  # automatically transmit to next state. Example: m state in "ma*bc" 
        self.prev_state = None
        self.transitionMap = {}

    def addTransition(self, ch, target):
        if ch not in self.transitionMap:
            self.transitionMap[ch] = set([target])
        else:
            self.transitionMap[ch].add(target)

    def allNextExceptSelf(self):
        ''' all the next nodes exclude self  '''
        ll = [v for k, v in self.transitionMap.items()]
        return [i for l in ll for i in l if i != self]

    def next(self, ch):
        ll = [ v for k, v in self.transitionMap.items() if self.charMatch(ch, k) ]
        res1 = [i for l in ll for i in l]
        res2 = []
        if self.autoTransit:
            # if autoTransit, then the transitionMap must only contain only one value
            temp = self.allNextExceptSelf()
            assert( len(temp) == 1 )
            res2 = temp[0].next(ch)
            #res2 = list(set(res2) - set([temp[0]]))
        return list(set(res2 + res1)) # res2 could contain duplicate items as res1
    
    def couldBeTail(self):
        ''' if this state could be the end state '''
        if len(self.transitionMap) == 0 or len(self.allNextExceptSelf())==0:
            return True
        if self.autoTransit:
            for i in self.allNextExceptSelf(): # use allNextExceptSelf in case of infinite loop
                if i.couldBeTail():
                    return True
        return False

    @staticmethod
    def charMatch(sch, pch):
        return sch == pch or pch == '.'

    def __repr__(self):
        return str(id(self) % 10000)

    def __hash__(self):
        return id(self)
# may need to compress some states to improve speed
# for example: ma*aaaaabc

class StateMachine:
    def __init__(self, pattern):
        import re
        pattern = re.sub(r'(\w\*)\1*', r'\1', pattern)  # pay attention to this regular expression. Must use (\w\*)\1*, cannot use (\w\*)+

        self.start = State() # start state
        s = self.start # s means current state
        self.states = [s]
        for idx, pch in enumerate(pattern):
            if pch == '*':
                s.prev_state.autoTransit = True  # s must have a prev state here
                s.addTransition( pattern[idx-1], s )
            else:
                s2 = State()
                s.addTransition(pch, s2)
                s2.prev_state = s
                s = s2
                self.states.append(s2)
            
    def match(self, state, s):
        if s == '':
            return state.couldBeTail()
        next_states = state.next(s[0])
        for next_state in next_states:
            if self.match(next_state, s[1:]):
                return True
        return False

    def print(self):
        for s in self.states:
            print ('state %s: ' % s )
            print ('\tautoTransit: %s' % s.autoTransit)
            for k,v in s.transitionMap.items():
                print ('\t%s -> %s' % (k, v) )

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # first char of p cannot be *
        if len(p)>0 and p[0] == '*':
            return False
        sm = StateMachine(pattern=p)
        #sm.print()
        return sm.match(sm.start, s)


assert (Solution().isMatch("bbbba", ".*a*a") == True)
assert (Solution().isMatch("aaa", "ab*a*c*a") == True)

assert (Solution().isMatch('abcd', 'abcd') == True )
assert (Solution().isMatch('aacd', 'a*cd') == True )
assert (Solution().isMatch('cd', 'a*cd') == True )
assert (Solution().isMatch('mcd', 'ma*cd') == True )
assert (Solution().isMatch('maaacd', 'ma*aaacd') == True )
assert (Solution().isMatch('aa', 'a*') == True )
assert (Solution().isMatch('aab', 'c*a*b') == True ) # xxxx

# must return False
assert (Solution().isMatch('maacd', 'ma*aaacd') == False )
assert (Solution().isMatch('aaaaaaaaaaaaab', 'a*a*a*a*a*a*a*a*a*a*c') == False )
assert (Solution().isMatch('aab', 'a*a*c') == False )


#test case
# abcd;  ma*aaabc; ma*bc; a*bc; ''



# d = {1:2, 3:4}
# v = list(d.values())[0]
# print(v)
