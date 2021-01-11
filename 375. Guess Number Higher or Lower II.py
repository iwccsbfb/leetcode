class Solution:
    # method0 is not correct, reason:
    # max{ f(1,i-1)+c1*x, f(i+1,k)+c2*x } != max{ f(1,i-1) , f(i+1,k)} + c*x ; where c is corresponding to the bigger f
    def getMoneyAmount0(self, n: int) -> int:
        # map i to (minimum money guaranteed to win, # of guesses that incur a cost)
        data = {1: (0, 0) }
        def f(a, b):
            if a > b: return 0, 0
            money, count = data[b-a+1]
            return money+count*(a-1), count
        MAX = n*(n+1)
        for k in range(2, n+1):
            money, count = MAX, k  # maximum possible value
            for i in range(1, k+1): # i range from 1 to k
                # choose maximum of two branches after first node
                m1, c1 = f(1,i-1)
                m2, c2 = f(i+1,k)
                if m1 > m2: 
                    m0, c0 = m1, c1
                else:
                    m0, c0 = m2, c2
                m = m0 + i
                c = c0 + 1
                # choose minimum of all possible first node
                if m < money:
                    money, count = m, c
            #if k == 8:
            #    print ((1,k), node)
            data[k] = (money, count)
        return data[n][0]

        
    def getMoneyAmount(self, n: int) -> int:
        # map (a,b) to the cost
        data = { }
        MAX = n*(n+1)
        for diff in range(-1, n): # end_indx - start_index == diff
            for i in range(1, n+1-diff): # start index: 1 to n-diff
                # calculate data[i, i+diff]
                if diff <= 0:
                    data[i, i+diff] = 0
                    continue
                money = MAX
                for j in range(i, i+diff+1):  # first node to choose
                    money = min(money, max(data[i, j-1], data[j+1, i+diff]) + j)
                data[i, i+diff] = money
        return data[1,n]
            
# print( Solution().getMoneyAmount0( 16 ) ) # 33 -- not correct
# print( Solution().getMoneyAmount( 10 ) )
#print( Solution().getMoneyAmount( 16 ) )

