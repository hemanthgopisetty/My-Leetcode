#User function Template for python3

class Solution:
    def count(self, coins, N, Sum):
        # code here
        dp=[[0 for i in range(Sum+1)] for j in range(N+1)]
        def dfs(coints,N,Sum):
            if Sum == 0 : return 1
        
            if N<=0 or Sum<0 : return 0
            
            if dp[N][Sum] : return dp[N][Sum]
            
            dp[N][Sum]=dfs(coins,N-1,Sum)+dfs(coins,N,Sum-coins[N-1])
            
            return dp[N][Sum]
        
        return dfs(coins,N,Sum)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        sum,N = list(map(int, input().strip().split()))
        coins = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.count(coins,N,sum))

# } Driver Code Ends