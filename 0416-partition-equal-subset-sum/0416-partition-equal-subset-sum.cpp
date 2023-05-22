class Solution {
public:
    //"DP problems are easy to understand only if you can deduce recursive relationship in the problem"
    bool canPartition(vector<int>& nums) {
       
       int totalSum=accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum % 2!=0)return false;
        
        int n=nums.size();
        
        totalSum/=2;
        
        vector<vector<bool>>dp(n+1,vector<bool>(totalSum+1,false));
        
        //base cases
        dp[0][0]=true;
        
        for(auto i=1;i<n+1;i++)
        {
            dp[i][0]=true;
        }
        
        for(auto j=1;j<totalSum+1;j++)
        {
            dp[0][j]=false;
        }
        
        for(auto i=1;i<n+1;i++)
        {
             for(auto j=1;j<totalSum+1;j++)
            {
                 
                //don't pick
                dp[i][j]=dp[i-1][j];
                //pick
                if(j>=nums[i-1])
                {
                    dp[i][j]=(dp[i-1][j] or dp[i-1][j-nums[i-1]]);
                } 
            }
        }
        return dp[n][totalSum];
    }
};