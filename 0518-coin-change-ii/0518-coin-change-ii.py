class Solution:
    def bottomUp(self, coins, target):
        n=len(coins)
        dp=[[0 for _ in range(target+1)]for _ in range(n)]
        
        for i in range(n):
            dp[i][0]=1
        for i in range(1,target+1):
            if i%coins[0]==0:
                dp[0][i]=1
        for i in range(1, n):
            coin = coins[i]
            for j in range(1, target + 1):
                if j - coin >= 0:
                    dp[i][j] = dp[i][j - coin] + dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j]
        
        return dp[-1][-1]
                
        
    def change(self, amount: int, coins: List[int]) -> int:
        return self.bottomUp(coins, amount)
        
        