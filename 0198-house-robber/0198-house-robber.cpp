//1.RECURSIVE WAY
//2.ITERATIVE WAY
//Many Sub Problems 
/*
2^n solution giving tle
so use memo
*/
class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return rob(nums,dp,nums.size()-1);
    }
    int rob(vector<int>&nums,vector<int>&dp,int i)
    {
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(nums[i]+rob(nums,dp,i-2),rob(nums,dp,i-1));
    }
};