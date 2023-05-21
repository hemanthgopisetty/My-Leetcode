class Solution {
public:
    int dfs(int amount, vector<int>& coins,int idx,vector<vector<int>>&dp)
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
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n+1,vector<int>(amt+1,-1));
        
        return dfs(amt,coins,0,dp);
    }
};