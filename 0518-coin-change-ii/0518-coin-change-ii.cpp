class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        vector<vector<int>>dp(n+2,vector<int>(amount+2,-1));
        for(auto i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
        for(auto j=0;j<amount+1;j++)
        {
            dp[0][j]=0;
        }
        for(auto i=1;i<n+1;i++)
        {
            for(auto j=1;j<amount+1;j++)
            {
                if(coins[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }
    /*int dfs(int amount, vector<int>& coins,int idx,vector<vector<int>>&dp)
    {
        if(idx==coins.size())
        {
            return 0;
        }
        
        if(amount == 0)
        {
            return 1;
        }
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        int take=0,dont_take=0;
        if(coins[idx]<=amount)
        {
            take=dfs(amount-coins[idx],coins,idx,dp);
        }
        dont_take=dfs(amount,coins,idx+1,dp);
        
        return dp[idx][amount]=take+dont_take;
    }*/
};