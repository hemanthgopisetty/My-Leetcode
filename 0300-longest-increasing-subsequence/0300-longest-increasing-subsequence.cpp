class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(size(nums),vector<int>(1+size(nums),-1));
        return lis(nums,dp,0,-1);
    }
    int lis(vector<int>&nums,vector<vector<int>>&dp,int i,int prev)
    {
        if(i>=size(nums))
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int p=0;
        int np=0;
        np=lis(nums,dp,i+1,prev);
        if(prev==-1 or nums[i]>nums[prev])p=1+lis(nums,dp,i+1,i);
        return dp[i][prev+1]=max(p,np);
    }
};