class Solution {
public:
    //"DP problems are easy to understand only if you can deduce recursive relationship in the problem"
    bool dfs(vector<int>& nums,vector<vector<bool>>& dp,vector<vector<bool>>& visited,int idx,int sum)
    {
        if(sum==0)return dp[idx][sum]=true;
        
        if(idx>=size(nums) or sum<0)return false;
        
        if(visited[idx][sum])return dp[idx][sum];
        
        visited[idx][sum]=true;
        
        return dp[idx][sum]=(dfs(nums,dp,visited,idx+1,sum) 
                                
                                    or
                             
                             dfs(nums,dp,visited,idx+1,sum-nums[idx])
                             
                            );
    }
    bool canPartition(vector<int>& nums) {
       
       int totalSum=accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum % 2!=0)return false;
        
        int n=nums.size();
        
        totalSum/=2;
        
        vector<vector<bool>>dp(n+1,vector<bool>((totalSum)+1,false));
        vector<vector<bool>>visited(n+1,vector<bool>((totalSum)+1,false));
        return dfs(nums,dp,visited,0,totalSum);
    }
};