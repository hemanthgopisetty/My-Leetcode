class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp=[[-1 for __ in range(amount+1)]for _ in range(len(coins)+1)]
        def dfs(coins,amt,i):
            
            if amt==0 :
                return 1
            
            if i>=len(coins):
                return 0
            
            
            if dp[i][amt] != -1 :
                return dp[i][amt]
            
            take=0
            
            if coins[i]<=amt :
                 take=dfs(coins,amt-coins[i],i)
            
            notTake=dfs(coins,amt,i+1)
            
            dp[i][amt]=take+notTake
            
            return dp[i][amt]
        
        return dfs(coins,amount,0)
            
        